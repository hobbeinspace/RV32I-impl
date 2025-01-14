/* ********************************************
 *	COSE222 Lab #5
 *
 *	Module: top design of the single-cycle CPU (single_cycle_cpu.sv)
 *  - Top design of the single-cycle CPU
 *
 *  Author: Gunjae Koo (gunjaekoo@korea.ac.kr)
 *
 * ********************************************
 */

`timescale 1ns/1ps

/* verilator lint_off UNUSED */
module single_cycle_cpu
#(  parameter IMEM_DEPTH = 1024,    // imem depth (default: 1024 entries = 4 KB)
              IMEM_ADDR_WIDTH = 10,
              REG_WIDTH = 32,
              DMEM_DEPTH = 1024,    // dmem depth (default: 1024 entries = 8 KB)
              DMEM_ADDR_WIDTH = 10 )
(
    input           clk,            // System clock
    input           reset_b         // Asychronous negative reset
);

    // Wires for datapath elements
    logic   [IMEM_ADDR_WIDTH-1:0]   imem_addr;
    logic   [31:0]  inst;   // instructions = an output of ????

    logic   [4:0]   rs1, rs2, rd;    // register numbers
    logic   [REG_WIDTH-1:0] rd_din;
    logic           reg_write;
    logic   [REG_WIDTH-1:0] rs1_dout, rs2_dout;

    logic   [REG_WIDTH-1:0] alu_in1, alu_in2;
    logic   [3:0]   alu_control;    // ALU control signal
    logic   [REG_WIDTH-1:0] alu_result;
    logic           alu_zero;
    logic           alu_sign;
    logic   [DMEM_ADDR_WIDTH-1:0]    dmem_addr;
    logic   [31:0]  dmem_din, dmem_dout;
    logic           mem_read, mem_write;



    // -------------------------------------------------------------------
    /* Main control unit:
     * Main control unit generates control signals for datapath elements
     * The control signals are determined by decoding instructions
     * Generating control signals using opcode = inst[6:0]
     */
    logic   [6:0]   opcode;
    logic   [5:0]   branch;
    logic   [1:0]   alu_src;
    logic           mem_to_reg;
    logic   [1:0]   alu_op;
    logic   [2:0]   funct3;


    logic [1:0] size;
    logic notsigned;
    logic isLUI;
    logic isAUIPC;
    logic isCompare;
    logic isJAL;
    logic isJALR;

    //logic         mem_read, mem_write, reg_write; // declared above
    // Note for Lab #5
    // The branch control signal has 4-bits since this processor supports beq, bne, blt, and bge
    // Each bit of the branch control signal represents the corresponding branch instruction
    // i.e., branch[0] = beq, branch[1] = bne, branch[2] = blt, branch[3] = bge

    // COMPLETE THE MAIN CONTROL UNIT HERE
    assign opcode = inst[6:0];
    assign branch[0] = ((opcode==7'b1100011) && (funct3==3'b000)) ? 1'b1: 1'b0;
    assign branch[1] = ((opcode==7'b1100011) && (funct3==3'b001)) ? 1'b1: 1'b0;
    assign branch[2] = ((opcode==7'b1100011) && (funct3==3'b100)) ? 1'b1: 1'b0;
    assign branch[3] = ((opcode==7'b1100011) && (funct3==3'b101)) ? 1'b1: 1'b0;
    
    assign branch[4] = ((opcode==7'b1100011) && (funct3==3'b110)) ? 1'b1: 1'b0; //bltu    
    assign branch[5] = ((opcode==7'b1100011) && (funct3==3'b111)) ? 1'b1: 1'b0; //bgeu

    assign mem_read = (opcode==7'b0000011) ? 1'b1: 1'b0;    // ld
    
    assign mem_write = (opcode==7'b0100011) ? 1'b1: 1'b0;   // sd
    assign mem_to_reg = mem_read;
    assign reg_write = (opcode==7'b0110011) | (opcode==7'b0010011) | mem_read | isAUIPC | isLUI | isCompare | isJAL | isJALR; // ld, r-type, or i-type
    assign alu_src = ( mem_read | mem_write | (opcode==7'b0010011) | isJALR) ? 2'b11 : (isAUIPC | isLUI ? 2'b01:2'b00);   // ld, sd, or i-type
    assign alu_op[0] = |branch;
    assign alu_op[1] = (opcode==7'b0110011) | (opcode==7'b0010011) | (opcode==7'b1100111);    // r-type or i-type

    assign isLUI=(opcode==7'b0110111);
    assign isAUIPC=(opcode==7'b0010111);
    assign isCompare=(opcode==7'b0110011 | opcode==7'b0010011) & (funct3==3'b010 | funct3==3'b011);
    assign isJAL=(opcode==7'b1101111);
    assign isJALR=(opcode==7'b1100111);
    assign size= funct3[1:0];
    assign notsigned= ((opcode==7'b0000011) & funct3[2]) | ((opcode==7'b0110011)& (funct3==3'b011)) | ((opcode==7'b0010011) & (funct3==3'b011)) | ((opcode==7'b1100011)& (funct3[1]==1'b1));




    // --------------------------------------------------------------------

    // --------------------------------------------------------------------
    /* ALU control unit:
     * ALU control unit generate alu_control signal which selects ALU operations
     * Generating control signals using alu_op, funct7, and funct3 fileds
     */
    logic   [6:0]   funct7;
    //logic   [2:0]   funct3;   // declared above

    // COMPLETE THE ALU CONTROL UNIT HERE
    assign funct7 = inst[31:25];
    assign funct3 = inst[14:12];

    always_comb begin
        if (alu_op[1]) begin
            case (funct3)
                3'b111: alu_control = 4'b0000;
                3'b110: alu_control = 4'b0001;
                3'b100: alu_control = 4'b0011;
                3'b001: alu_control = 4'b0111;
                3'b101: alu_control = (funct7==7'b0000000 ? 4'b1001 : 4'b1011);
                3'b010: alu_control = 4'b0110;
                3'b011: alu_control = 4'b1110;
                default: alu_control = (funct7[5] && (opcode==7'b0110011)) ? 4'b0110: 4'b0010;
            endcase
        end else begin
            alu_control = (alu_op[0]) ? (notsigned? 4'b1110: 4'b0110): 4'b0010;
        end
    end


    // ---------------------------------------------------------------------


    // ---------------------------------------------------------------------
    /* Immediate generator:
     * Generating immediate value from inst[31:0]
     * We require immediate type data for load, store, i-type, and branch instructions
     */
    logic   [REG_WIDTH-1:0]  imm32;
    logic   [REG_WIDTH-1:0]  imm32_branch;  // imm32 left shifted by 1
    logic   [11:0]  imm12;  // 12-bit immediate value extracted from inst
    logic [REG_WIDTH-1:0] imm32_U;
    logic [REG_WIDTH-1:0] imm32_J;


    // COMPLETE IMMEDIATE GENERATOR HERE
    assign imm12 = (|branch) ? {inst[31], inst[7], inst[30:25], inst[11:8]}: 
                ( (mem_write) ? {inst[31:25], inst[11:7]}: inst[31:20] );
    assign imm32 = { {20{imm12[11]}}, imm12 };
    assign imm32_branch = {imm32[30:0], 1'b0}; // << 1 for branch

    assign imm32_U = {inst[31:12],{12{1'b0}}};
    assign imm32_J = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0};


    // ----------------------------------------------------------------------

    // Program counter
    logic   [31:0]  pc_curr, pc_next;
    logic   [1:0]   pc_next_sel;    // selection signal for pc_next
    logic   [31:0]  pc_next_plus4, pc_next_branch;
    logic   [31:0]  pc_next_JAL;


    assign pc_next_plus4 = pc_curr + 4;    // FILL THIS
    assign pc_next_JAL=pc_curr+imm32_J;

    always_ff @ (posedge clk or negedge reset_b) begin
        if (~reset_b) begin
            pc_curr <= 'b0;
        end else begin
            pc_curr <= pc_next;        // FILL THIS
        end
    end


    // MUXes:
    // COMPLETE MUXES HERE
    // PC_NEXT
    assign pc_next_sel = ((branch[0] & alu_zero) | (branch[1] & ~alu_zero) | (branch[2] & alu_sign) | (branch[3] & ~alu_sign) | (branch[4] & alu_sign) | (branch[5] & ~alu_sign))
                            ? 2'b11: (isJAL? 2'b10 : (isJALR? 2'b01: 2'b00));      // FILL THIS
    assign pc_next = pc_next_sel==2'b11 ? pc_next_branch: pc_next_sel==2'b10 ? pc_next_JAL: pc_next_sel==2'b01 ? alu_result: pc_next_plus4; // if branch is taken, pc_next_sel=1'b1
    assign pc_next_branch = pc_curr + imm32_branch;   // FILL THIS

    // ALU inputs
    assign alu_in1 = isAUIPC?pc_curr:rs1_dout;
    assign alu_in2 = (alu_src==2'b11) ? imm32: ((alu_src==2'b01)? imm32_U:rs2_dout);

    // RF din
    logic [REG_WIDTH-1:0] comp_result;
    assign comp_result={{31{1'b0}},alu_sign};
    assign rd_din =(isJAL | isJALR)? pc_next_plus4: (isCompare?comp_result:isLUI?imm32_U:((mem_to_reg) ? dmem_dout: alu_result));

    // COMPLETE CONNECTIONS HERE    
    // imem
    assign imem_addr = pc_curr[IMEM_ADDR_WIDTH+1:2];

    // regfile
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    assign rd = inst[11:7];

    // dmem
    assign dmem_addr = alu_result[DMEM_ADDR_WIDTH+1:2];
    assign dmem_din = rs2_dout;
 

    // -----------------------------------------------------------------------
    /* Instantiation of datapath elements
     * All input/output ports should be connected
     */
    
    // IMEM
    imem #(
        .IMEM_DEPTH         (IMEM_DEPTH),
        .IMEM_ADDR_WIDTH    (IMEM_ADDR_WIDTH)
    ) u_imem_0 (
        .addr               ( imem_addr     ),
        .dout               ( inst          )
    );

    // REGFILE
    regfile #(
        .REG_WIDTH          (REG_WIDTH)
    ) u_regfile_0 (
        .clk                (clk),
        .rs1                (rs1),
        .rs2                (rs2),
        .rd                 (rd),
        .rd_din             (rd_din),
        .reg_write          (reg_write),
        .rs1_dout           (rs1_dout),
        .rs2_dout           (rs2_dout)
    );

    // ALU
    alu #(
        .REG_WIDTH          (REG_WIDTH)
    ) u_alu_0 (
        .in1                (alu_in1),
        .in2                (alu_in2),
        .alu_control        (alu_control),
        .result             (alu_result),
        .zero               (alu_zero),
        .sign               (alu_sign)
    );

    // DMEM
    dmem #(
        .DMEM_DEPTH         (DMEM_DEPTH),
        .DMEM_ADDR_WIDTH    (DMEM_ADDR_WIDTH)
    ) u_dmem_0 (
        .clk                (clk),
        .addr               (dmem_addr),
        .din                (dmem_din),
        .notsigned          (notsigned),
        .size               (size),
        .mem_read           (mem_read),
        .mem_write          (mem_write),
        .dout               (dmem_dout)
    );

endmodule
