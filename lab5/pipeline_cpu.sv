/* ********************************************
 *	COSE222 Lab #5
 *
 *	Module: pipelined_cpu.sv
 *  - Top design of the 5-stage pipelined RISC-V processor
 *  - Processor supports lw, sw, add, sub, or, and, beq, bne, blt, bge
 *
 *  Author: Gunjae Koo (gunjaekoo@korea.ac.kr)
 *
 * ********************************************
 */

`timescale 1ns/1ps

// Packed structures for pipeline registers
// COMPLETE THE PIPELINE INTERFACES USING PACKED STRUCTURES
// Pipe reg: IF/ID
typedef struct packed {
    logic   [31:0]  pc;
    logic   [31:0]  inst;  

    logic   [31:0]  pc_next_plus4;
} pipe_if_id;

// Pipe reg: ID/EX
typedef struct packed {
    logic   [31:0]  pc;
    logic   [31:0]  rs1_dout;
    logic   [31:0]  rs2_dout;
    logic   [31:0]  imm32;
	logic	[6:0]	opcode;
    logic   [2:0]   funct3;
    logic   [6:0]   funct7;
    logic   [3:0]   branch;     // branch[0] = beq, branch[1] = bne, branch[2] = blt, branch[3] = bge
    logic   [1:0]   alu_src;
    logic   [1:0]   alu_op;
    logic           mem_read;
    logic           mem_write;
    logic   [4:0]   rs1;
    logic   [4:0]   rs2;
    logic   [4:0]   rd;         // rd for regfile
    logic           reg_write;
    logic           mem_to_reg;

    logic [31:0]    imm32_U;
    logic [31:0]    imm32_J;
    logic isLUI;
    logic isAUIPC;
    logic isCompare;
    logic isJAL;
    logic isJALR;
    logic   [1:0]   size;
    logic notsigned;
    logic   [31:0]  pc_next_plus4;

    
} pipe_id_ex;

// Pipe reg: EX/MEM
typedef struct packed {
    logic   [31:0]  alu_result; // for address
    logic   [31:0]  rs2_dout;   // for store
    logic           mem_read;
    logic           mem_write;
    logic   [4:0]   rd;
    logic           reg_write;
    logic           mem_to_reg;
    

    logic   [31:0]  pc_next_plus4;
    logic notsigned;
    logic   [1:0] size;
    logic isJALR;
    logic isJAL;
    logic isCompare;
    logic   [31:0]    comp_result;
    logic isLUI;
    logic   [31:0]  imm32_U;
} pipe_ex_mem;

// Pipe reg: MEM/WB
typedef struct packed {
    logic   [31:0]  alu_result;
    logic   [31:0]  dmem_dout;
    logic   [4:0]   rd;
    logic           reg_write;
    logic           mem_to_reg;

    logic isJAL;
    logic isJALR;
    logic   [31:0]  pc_next_plus4;
    logic isCompare;
    logic   [31:0]  comp_result;
    logic isLUI;
    logic   [31:0]  imm32_U;
} pipe_mem_wb;

/* verilator lint_off UNUSED */
module pipeline_cpu
#(  parameter IMEM_DEPTH = 1024,    // imem depth (default: 1024 entries = 4 KB)
              IMEM_ADDR_WIDTH = 10,
              REG_WIDTH = 32,
              DMEM_DEPTH = 1024,    // dmem depth (default: 1024 entries = 8 KB)
              DMEM_ADDR_WIDTH = 10 )
(
    input           clk,            // System clock
    input           reset_b         // Asychronous negative reset
);

    // -------------------------------------------------------------------
    /* Instruction fetch stage:
     * - Accessing the instruction memory with PC
     * - Control PC udpates for pipeline stalls
     */

    // Program counter
    logic           pc_write;   // enable PC updates
    logic   [31:0]  pc_curr, pc_next;
    logic   [31:0]  pc_next_plus4, pc_next_branch;
    logic   [1:0]   pc_next_sel;
    logic           branch_taken;


    logic   [31:0]  pc_next_JAL;
    logic   [31:0]  pc_next_JALR;
    
    //logic           regfile_zero;   // zero detection from regfile, REMOVED

    assign pc_next_plus4 = pc_curr + 4;
    //assign pc_next_sel = (branch_taken?'b1:'b0); 

    assign pc_next_sel = branch_taken? 2'b11: isJAL? 2'b10 : ex.isJALR? 2'b01: 2'b00;      // FILL THIS

    //assign pc_next = (pc_next_sel) ? pc_next_branch: pc_next_plus4;
    assign pc_next = pc_next_sel==2'b11 ? pc_next_branch: pc_next_sel==2'b10 ? pc_next_JAL: pc_next_sel==2'b01 ? pc_next_JALR: pc_next_plus4; // if branch is taken, pc_next_sel=1'b1
    
    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            pc_curr <= 'b0;
        end else if (pc_write) begin
             pc_curr<=pc_next;
        end
    end

    // imem
    logic   [IMEM_ADDR_WIDTH-1:0]   imem_addr;
    logic   [31:0]  inst;   // instructions = an output of ????
    
    assign imem_addr = pc_curr[IMEM_ADDR_WIDTH+1:2];

    // instantiation: instruction memory
    imem #(
        .IMEM_DEPTH         (IMEM_DEPTH),
        .IMEM_ADDR_WIDTH    (IMEM_ADDR_WIDTH)
    ) u_imem_0 (
        .addr               ( imem_addr     ),
        .dout               ( inst          )
    );
    // -------------------------------------------------------------------

    // -------------------------------------------------------------------
    /* IF/ID pipeline register
     * - Supporting pipeline stalls and flush
     */
    pipe_if_id      id;         // THINK WHY THIS IS ID...
    pipe_id_ex      ex;
    pipe_ex_mem     mem;
    pipe_mem_wb     wb;

    logic           if_flush, if_stall;

    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            id <= 'b0;
        end else begin
            if (  if_flush ) begin
                id <= 'b0;
            end else if (  ~if_stall ) begin
                id.pc <=  pc_curr;
                id.inst <=  inst;

                id.pc_next_plus4<=pc_next_plus4;
            end
        end
    end
    // -------------------------------------------------------------------

    // ------------------------------------------------------------------
    /* Instruction decoder stage:
     * - Generating control signals
     * - Register file
     * - Immediate generator
     * - Hazard detection unit
     */
    
    // -------------------------------------------------------------------
    /* Main control unit:
     * Main control unit generates control signals for datapath elements
     * The control signals are determined by decoding instructions
     * Generating control signals using opcode = inst[6:0]
     */
    logic   [6:0]   opcode;
    logic   [3:0]   branch;
    logic   [1:0]   alu_src;
    logic           mem_to_reg;
    logic   [1:0]   alu_op;
    logic           mem_read, mem_write, reg_write; // declared above
    logic   [6:0]   funct7;
    logic   [2:0]   funct3;

    
    logic notsigned;
    logic   [1:0] size;
    logic isLUI;
    logic isAUIPC;
    logic isCompare;
    logic isJAL;
    logic isJALR;

    // COMPLETE THE MAIN CONTROL UNIT HERE
    assign opcode=id.inst[6:0];
    assign branch[0] = ((opcode==7'b1100011) && (funct3==3'b000)) ? 1'b1: 1'b0;
    assign branch[1] = ((opcode==7'b1100011) && (funct3==3'b001)) ? 1'b1: 1'b0;
    assign branch[2] = ((opcode==7'b1100011) && (funct3==3'b100)) ? 1'b1: 1'b0;
    assign branch[3] = ((opcode==7'b1100011) && (funct3==3'b101)) ? 1'b1: 1'b0;

    assign mem_read = (opcode==7'b0000011) ? 1'b1: 1'b0;    // ld
    assign mem_write = (opcode==7'b0100011) ? 1'b1: 1'b0;   // sd
    assign mem_to_reg = mem_read;
    assign reg_write = (opcode==7'b0110011) | (opcode==7'b0010011) | mem_read | isAUIPC | isLUI | isCompare | isJAL | isJALR;
    assign alu_src = ( mem_read | mem_write | (opcode==7'b0010011) | isJALR) ? 2'b11 : (isAUIPC | isLUI ? 2'b01:2'b00);   // ld, sd, or i-type

    assign alu_op[0] = |branch;
    assign alu_op[1] = (opcode==7'b0110011) | (opcode==7'b0010011) | (opcode==7'b1100111);

    assign funct7 = id.inst[31:25];
    assign funct3 = id.inst[14:12];

    assign isLUI=(opcode==7'b0110111);
    assign isAUIPC=(opcode==7'b0010111);
    assign isCompare=(opcode==7'b0110011 | opcode==7'b0010011) & (funct3==3'b010 | funct3==3'b011);
    assign isJAL=(opcode==7'b1101111);
    assign isJALR=(opcode==7'b1100111);
    assign size= funct3[1:0];
    assign notsigned= ((opcode==7'b0000011) & funct3[2]) | ((opcode==7'b0110011)& (funct3==3'b011)) | ((opcode==7'b0010011) & (funct3==3'b011)) | ((opcode==7'b1100011)& (funct3[1]==1'b1));


    // --------------------------------------------------------------------

    // ---------------------------------------------------------------------
    /* Immediate generator:
     * Generating immediate value from inst[31:0]
     */
    logic   [31:0]  imm32;
    logic   [31:0]  imm32_branch;  // imm64 left shifted by 1

    // COMPLETE IMMEDIATE GENERATOR HERE
    logic   [11:0]  imm12;
    logic [REG_WIDTH-1:0] imm32_U;
    logic [REG_WIDTH-1:0] imm32_J;


    assign imm12 = (|branch) ? {id.inst[31], id.inst[7], id.inst[30:25], id.inst[11:8]}: 
                ( (mem_write) ? {id.inst[31:25], id.inst[11:7]}: id.inst[31:20] );
    assign imm32 = { {20{imm12[11]}}, imm12 };
    assign imm32_branch = {imm32[30:0], 1'b0};  // << 1 for branch
    assign imm32_U = {id.inst[31:12],{12{1'b0}}};
    assign imm32_J = {{12{id.inst[31]}},id.inst[19:12],id.inst[20],id.inst[30:21],1'b0};



    // Computing branch target
    assign pc_next_branch =  ex.pc +{ex.imm32[30:0], 1'b0};
    assign pc_next_JAL=id.pc+imm32_J;
    assign pc_next_JALR=alu_result;

    // ----------------------------------------------------------------------

    // ----------------------------------------------------------------------
    /* Hazard detection unit
     * - Detecting data hazards from load instrcutions
     * - Detecting control hazards from taken branches
     */
    logic   [4:0]   rs1, rs2;

    logic           stall_by_load_use;
    logic           flush_by_branch;
    
    logic           id_stall, id_flush;


    assign stall_by_load_use = (ex.mem_read&ex.rd!=0)?(((ex.rd==rs1)|(ex.rd==rs2))?'b1:'b0):'b0;
    assign flush_by_branch =  branch_taken?'b1:'b0;
  
    assign id_flush =  flush_by_branch | ex.isJALR;
    assign id_stall =  stall_by_load_use;
	
    assign if_flush =  flush_by_branch | isJAL | ex.isJALR; 
    assign if_stall =  stall_by_load_use;


    assign pc_write =  ~stall_by_load_use;

    // ----------------------------------------------------------------------


    // regfile/
    logic   [4:0]   rd;    // register numbers
    logic   [REG_WIDTH-1:0] rd_din;
    logic   [REG_WIDTH-1:0] rs1_dout, rs2_dout;
    
    assign rs1 = id.inst[19:15];      // our processor does NOT support U and UJ types
    assign rs2 =  id.inst[24:20];    // consider ld and i-type
    assign rd = id.inst[11:7];
    // rd, rd_din, and reg_write will be determined in WB stage
    
    // instnatiation of register file
    regfile #(
        .REG_WIDTH          (REG_WIDTH)
    ) u_regfile_0 (
        .clk                ( clk ),
        .rs1                ( rs1 ),
        .rs2                ( rs2 ),
        .rd                 ( wb.rd ),
        .rd_din             ( rd_din),
        .reg_write          ( wb.reg_write ),
        .rs1_dout           ( rs1_dout),
        .rs2_dout           ( rs2_dout )
    );

    //assign regfile_zero = ~|(rs1_dout ^ rs2_dout); // REMOVED

    // ------------------------------------------------------------------

    // -------------------------------------------------------------------
    /* ID/EX pipeline register
     * - Supporting pipeline stalls
     */
    //pipe_id_ex      ex;         // THINK WHY THIS IS EX...

    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            ex <= 'b0;
        end else begin
            if(id_flush|id_stall) begin
                ex<='b0;
            end 
            else if(~id_stall) begin
                ex.pc<=id.pc;
                ex.rs1_dout<=rs1_dout;
                ex.rs2_dout<=rs2_dout;
                ex.imm32<=imm32;
                ex.opcode<=opcode;
                ex.funct3<=funct3;
                ex.funct7<=funct7;
                ex.branch<=branch;
                ex.alu_src<=alu_src;
                ex.alu_op<=alu_op;
                ex.mem_read<=mem_read;
                ex.mem_write<=mem_write;
                ex.rs1<=rs1;
                ex.rs2<=rs2;
                ex.rd<=rd; //?
                ex.reg_write<=reg_write;
                ex.mem_to_reg<=mem_to_reg;

                ex.imm32_U<=imm32_U;
                ex.imm32_J<=imm32_J;
                ex.isLUI<=isLUI;
                ex.isAUIPC<=isAUIPC;
                ex.isCompare<=isCompare;
                ex.isJAL<=isJAL;
                ex.isJALR<=isJALR;
                ex.size<=size;
                ex.notsigned<=notsigned;
                ex.pc_next_plus4<=id.pc_next_plus4;
            end			 
        end
    end

    // ------------------------------------------------------------------

    // ------------------------------------------------------------------
    /* Excution stage:
     * - ALU & ALU control
     * - Data forwarding unit
     */

    // --------------------------------------------------------------------
    /* ALU control unit:
     * ALU control unit generate alu_control signal which selects ALU operations
     * Generating control signals using alu_op, funct7, and funct3 fileds
     */

    logic   [3:0]   alu_control;    // ALU control signal

    // COMPLETE ALU CONTROL UNIT
	    always_comb begin
        if (ex.alu_op[1]) begin
            case (ex.funct3)
                3'b111: alu_control = 4'b0000;
                3'b110: alu_control = 4'b0001;
                3'b100: alu_control = 4'b0011;    

                3'b001: alu_control = 4'b0111;
                3'b101: alu_control = (ex.funct7==7'b0000000 ? 4'b1001 : 4'b1011);
                3'b010: alu_control = 4'b0110;
                3'b011: alu_control = 4'b1110;

                default: alu_control = (ex.funct7[5] && (ex.opcode==7'b0110011)) ? 4'b0110: 4'b0010;
            endcase
        end else begin
            alu_control = (alu_op[0]) ? (ex.notsigned? 4'b1110: 4'b0110): 4'b0010;
        end
    end

    // ---------------------------------------------------------------------

    // ----------------------------------------------------------------------
    /* Forwarding unit:
     * - Forwarding from EX/MEM and MEM/WB
     */
    logic   [1:0]   forward_a, forward_b;
    logic   [REG_WIDTH-1:0]  alu_fwd_in1, alu_fwd_in2;   // outputs of forward MUXes

	/* verilator lint_off CASEX */
   // COMPLETE FORWARDING MUXES
   
   always_comb begin
    case(forward_a)
        2'b00:alu_fwd_in1=ex.rs1_dout;
        2'b10:alu_fwd_in1=mem.alu_result;
        2'b01:alu_fwd_in1=wb.dmem_dout;
        default:alu_fwd_in1=ex.rs1_dout;
    endcase
   end
   always_comb begin
    case(forward_b)
        2'b00:alu_fwd_in2=ex.rs2_dout;
        2'b10:alu_fwd_in2=mem.alu_result;
        2'b01:alu_fwd_in2=wb.dmem_dout;
        default:alu_fwd_in2=ex.rs2_dout;
    endcase
   end  
	/* verilator lint_on CASEX */

	// COMPLETE THE FORWARDING UNIT
    // Need to prioritize forwarding conditions
    assign forward_a = ((mem.reg_write) && (mem.rd != 0) && (mem.rd == ex.rs1)) ? 2'b10 :
                       ((wb.reg_write) && (wb.rd != 0) && (wb.rd == ex.rs1)) ? 2'b01 : 2'b00;

    assign forward_b = ((mem.reg_write) && (mem.rd != 0) && (mem.rd == ex.rs2)) ? 2'b10 :
                       ((wb.reg_write) && (wb.rd != 0) && (wb.rd == ex.rs2)) ? 2'b01 : 2'b00;

    // -----------------------------------------------------------------------

    // ALU
    logic   [REG_WIDTH-1:0] alu_in1, alu_in2;
    logic   [REG_WIDTH-1:0] alu_result;
    //logic           alu_zero;   // will not be used

    assign alu_in1 =  ex.isAUIPC?ex.pc:alu_fwd_in1;
    //assign alu_in2 =  ex.alu_src?ex.imm32:alu_fwd_in2;
    assign alu_in2= (ex.alu_src==2'b11) ? ex.imm32: ((ex.alu_src==2'b01)? ex.imm32_U:alu_fwd_in2);

    // instantiation: ALU
    alu #(
        .REG_WIDTH          (REG_WIDTH)
    ) u_alu_0 (
        .in1                (alu_in1),
        .in2                (alu_in2),
        .alu_control        (alu_control),
        .result             (alu_result)
        //.zero               (alu_zero),	// REMOVED
		//.sign				(alu_sign)		// REMOVED
    );

    // branch unit (BU)
    logic   [REG_WIDTH-1:0] sub_for_branch;
    logic           bu_zero, bu_sign;
    logic bu_unsigned_comparison;
    //logic           branch_taken;

    assign sub_for_branch =  alu_fwd_in1-alu_fwd_in2;
    assign bu_zero =  sub_for_branch==0?'b1:'b0;
    assign bu_sign =  sub_for_branch[REG_WIDTH-1];

    assign bu_unsigned_comparison=$unsigned(alu_fwd_in1)<$unsigned(alu_fwd_in2);

    assign branch_taken =  (ex.branch[0] & bu_zero) | (ex.branch[1] & ~bu_zero) | (ex.branch[2] & bu_unsigned_comparison) | (ex.branch[3] & ~bu_unsigned_comparison);



    logic   [31:0]  comp_result;
    assign comp_result={{31{1'b0}},alu_result[REG_WIDTH-1]};

    // -------------------------------------------------------------------------
    /* Ex/MEM pipeline register
     */
    //pipe_ex_mem     mem;

    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            mem <= 'b0;
        end else begin
            mem.alu_result<=alu_result;
            mem.rs2_dout<=ex.rs2_dout;
            mem.mem_read<=ex.mem_read;
            mem.mem_write<=ex.mem_write;
            mem.rd<=ex.rd;
            mem.reg_write<=ex.reg_write;
            mem.mem_to_reg<=ex.mem_to_reg;

            mem.pc_next_plus4<=ex.pc_next_plus4;
            mem.notsigned<=ex.notsigned;
            mem.size<=ex.size;
            mem.isJALR<=ex.isJALR;
            mem.isJAL<=ex.isJAL;
            mem.isCompare<=ex.isCompare;
            mem.comp_result<=comp_result;
            mem.isLUI<=ex.isLUI;
            mem.imm32_U<=ex.imm32_U;

              
        end
    end


    // --------------------------------------------------------------------------
    /* Memory srage
     * - Data memory accesses
     */

    // dmem
    logic   [DMEM_ADDR_WIDTH-1:0]    dmem_addr;
    logic   [31:0]  dmem_din, dmem_dout;

    assign dmem_addr =  mem.alu_result[DMEM_ADDR_WIDTH+1:2];
    assign dmem_din =  mem.rs2_dout;
    
    // instantiation: data memory
    dmem #(
        .DMEM_DEPTH         (DMEM_DEPTH),
        .DMEM_ADDR_WIDTH    (DMEM_ADDR_WIDTH)
    ) u_dmem_0 (
        .clk                (clk),
        .addr               (dmem_addr),
        .din                (dmem_din),
        .notsigned          (mem.notsigned),
        .size               (mem.size),
        .mem_read           ( mem.mem_read ),
        .mem_write          ( mem.mem_write ),
        .dout               (dmem_dout)
    );


    // -----------------------------------------------------------------------
    /* MEM/WB pipeline register
     */

    //pipe_mem_wb         wb;

    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            wb <= 'b0;
        end else begin
            wb.alu_result<=mem.alu_result;
            wb.dmem_dout<=dmem_dout;
            wb.rd<=mem.rd;
            wb.reg_write<=mem.reg_write;
            wb.mem_to_reg<=mem.mem_to_reg;
            wb.isJAL<=mem.isJAL;
            wb.isJALR<=mem.isJALR;
            wb.pc_next_plus4<=mem.pc_next_plus4;
            wb.isCompare<=mem.isCompare;
            wb.isLUI<=mem.isLUI;
            wb.imm32_U<=mem.imm32_U;
            wb.comp_result<=mem.comp_result;

        end
    end

    // ----------------------------------------------------------------------
    /* Writeback stage
     * - Write results to regsiter file
     */
    
    //assign rd_din =  wb.mem_to_reg?wb.dmem_dout:wb.alu_result;
    assign rd_din =(wb.isJAL | wb.isJALR)? wb.pc_next_plus4:
                   (wb.isCompare?wb.comp_result:
                   wb.isLUI?wb.imm32_U:
                   ((wb.mem_to_reg) ? wb.dmem_dout: wb.alu_result));
endmodule
