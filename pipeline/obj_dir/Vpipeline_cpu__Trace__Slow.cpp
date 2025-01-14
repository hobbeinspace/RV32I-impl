// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpipeline_cpu__Syms.h"


//======================

void Vpipeline_cpu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vpipeline_cpu::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vpipeline_cpu::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vpipeline_cpu::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vpipeline_cpu::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+117,"clk", false,-1);
        tracep->declBit(c+118,"reset_b", false,-1);
        tracep->declBus(c+123,"pipeline_cpu IMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+124,"pipeline_cpu IMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+125,"pipeline_cpu REG_WIDTH", false,-1, 31,0);
        tracep->declBus(c+123,"pipeline_cpu DMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+124,"pipeline_cpu DMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBit(c+117,"pipeline_cpu clk", false,-1);
        tracep->declBit(c+118,"pipeline_cpu reset_b", false,-1);
        tracep->declBit(c+66,"pipeline_cpu pc_write", false,-1);
        tracep->declBus(c+2,"pipeline_cpu pc_curr", false,-1, 31,0);
        tracep->declBus(c+119,"pipeline_cpu pc_next", false,-1, 31,0);
        tracep->declBus(c+3,"pipeline_cpu pc_next_plus4", false,-1, 31,0);
        tracep->declBus(c+67,"pipeline_cpu pc_next_branch", false,-1, 31,0);
        tracep->declBus(c+68,"pipeline_cpu pc_next_sel", false,-1, 1,0);
        tracep->declBit(c+69,"pipeline_cpu branch_taken", false,-1);
        tracep->declBus(c+4,"pipeline_cpu pc_next_JAL", false,-1, 31,0);
        tracep->declBus(c+70,"pipeline_cpu pc_next_JALR", false,-1, 31,0);
        tracep->declBus(c+5,"pipeline_cpu imem_addr", false,-1, 9,0);
        tracep->declBus(c+6,"pipeline_cpu inst", false,-1, 31,0);
        tracep->declArray(c+7,"pipeline_cpu id", false,-1, 95,0);
        tracep->declArray(c+71,"pipeline_cpu ex", false,-1, 275,0);
        tracep->declArray(c+80,"pipeline_cpu mem", false,-1, 175,0);
        tracep->declArray(c+86,"pipeline_cpu wb", false,-1, 170,0);
        tracep->declBit(c+120,"pipeline_cpu if_flush", false,-1);
        tracep->declBit(c+92,"pipeline_cpu if_stall", false,-1);
        tracep->declBus(c+10,"pipeline_cpu opcode", false,-1, 6,0);
        tracep->declBus(c+11,"pipeline_cpu branch", false,-1, 3,0);
        tracep->declBus(c+12,"pipeline_cpu alu_src", false,-1, 1,0);
        tracep->declBit(c+13,"pipeline_cpu mem_to_reg", false,-1);
        tracep->declBus(c+14,"pipeline_cpu alu_op", false,-1, 1,0);
        tracep->declBit(c+13,"pipeline_cpu mem_read", false,-1);
        tracep->declBit(c+15,"pipeline_cpu mem_write", false,-1);
        tracep->declBit(c+16,"pipeline_cpu reg_write", false,-1);
        tracep->declBus(c+17,"pipeline_cpu funct7", false,-1, 6,0);
        tracep->declBus(c+18,"pipeline_cpu funct3", false,-1, 2,0);
        tracep->declBit(c+19,"pipeline_cpu notsigned", false,-1);
        tracep->declBus(c+20,"pipeline_cpu size", false,-1, 1,0);
        tracep->declBit(c+21,"pipeline_cpu isLUI", false,-1);
        tracep->declBit(c+22,"pipeline_cpu isAUIPC", false,-1);
        tracep->declBit(c+23,"pipeline_cpu isCompare", false,-1);
        tracep->declBit(c+24,"pipeline_cpu isJAL", false,-1);
        tracep->declBit(c+25,"pipeline_cpu isJALR", false,-1);
        tracep->declBus(c+26,"pipeline_cpu imm32", false,-1, 31,0);
        tracep->declBus(c+27,"pipeline_cpu imm32_branch", false,-1, 31,0);
        tracep->declBus(c+28,"pipeline_cpu imm12", false,-1, 11,0);
        tracep->declBus(c+29,"pipeline_cpu imm32_U", false,-1, 31,0);
        tracep->declBus(c+30,"pipeline_cpu imm32_J", false,-1, 31,0);
        tracep->declBus(c+31,"pipeline_cpu rs1", false,-1, 4,0);
        tracep->declBus(c+32,"pipeline_cpu rs2", false,-1, 4,0);
        tracep->declBit(c+92,"pipeline_cpu stall_by_load_use", false,-1);
        tracep->declBit(c+93,"pipeline_cpu flush_by_branch", false,-1);
        tracep->declBit(c+92,"pipeline_cpu id_stall", false,-1);
        tracep->declBit(c+94,"pipeline_cpu id_flush", false,-1);
        tracep->declBus(c+33,"pipeline_cpu rd", false,-1, 4,0);
        tracep->declBus(c+95,"pipeline_cpu rd_din", false,-1, 31,0);
        tracep->declBus(c+121,"pipeline_cpu rs1_dout", false,-1, 31,0);
        tracep->declBus(c+122,"pipeline_cpu rs2_dout", false,-1, 31,0);
        tracep->declBus(c+96,"pipeline_cpu alu_control", false,-1, 3,0);
        tracep->declBus(c+97,"pipeline_cpu forward_a", false,-1, 1,0);
        tracep->declBus(c+98,"pipeline_cpu forward_b", false,-1, 1,0);
        tracep->declBus(c+99,"pipeline_cpu alu_fwd_in1", false,-1, 31,0);
        tracep->declBus(c+100,"pipeline_cpu alu_fwd_in2", false,-1, 31,0);
        tracep->declBus(c+101,"pipeline_cpu alu_in1", false,-1, 31,0);
        tracep->declBus(c+102,"pipeline_cpu alu_in2", false,-1, 31,0);
        tracep->declBus(c+70,"pipeline_cpu alu_result", false,-1, 31,0);
        tracep->declBus(c+103,"pipeline_cpu sub_for_branch", false,-1, 31,0);
        tracep->declBit(c+104,"pipeline_cpu bu_zero", false,-1);
        tracep->declBit(c+105,"pipeline_cpu bu_sign", false,-1);
        tracep->declBit(c+106,"pipeline_cpu bu_unsigned_comparison", false,-1);
        tracep->declBus(c+107,"pipeline_cpu comp_result", false,-1, 31,0);
        tracep->declBus(c+108,"pipeline_cpu dmem_addr", false,-1, 9,0);
        tracep->declBus(c+109,"pipeline_cpu dmem_din", false,-1, 31,0);
        tracep->declBus(c+110,"pipeline_cpu dmem_dout", false,-1, 31,0);
        tracep->declBus(c+123,"pipeline_cpu u_imem_0 IMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+124,"pipeline_cpu u_imem_0 IMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+5,"pipeline_cpu u_imem_0 addr", false,-1, 9,0);
        tracep->declBus(c+6,"pipeline_cpu u_imem_0 dout", false,-1, 31,0);
        tracep->declBus(c+1,"pipeline_cpu u_imem_0 unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+125,"pipeline_cpu u_regfile_0 REG_WIDTH", false,-1, 31,0);
        tracep->declBit(c+117,"pipeline_cpu u_regfile_0 clk", false,-1);
        tracep->declBus(c+31,"pipeline_cpu u_regfile_0 rs1", false,-1, 4,0);
        tracep->declBus(c+32,"pipeline_cpu u_regfile_0 rs2", false,-1, 4,0);
        tracep->declBus(c+111,"pipeline_cpu u_regfile_0 rd", false,-1, 4,0);
        tracep->declBus(c+95,"pipeline_cpu u_regfile_0 rd_din", false,-1, 31,0);
        tracep->declBit(c+112,"pipeline_cpu u_regfile_0 reg_write", false,-1);
        tracep->declBus(c+121,"pipeline_cpu u_regfile_0 rs1_dout", false,-1, 31,0);
        tracep->declBus(c+122,"pipeline_cpu u_regfile_0 rs2_dout", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+34+i*1,"pipeline_cpu u_regfile_0 rf_data", true,(i+0), 31,0);}}
        tracep->declBus(c+125,"pipeline_cpu u_alu_0 REG_WIDTH", false,-1, 31,0);
        tracep->declBus(c+101,"pipeline_cpu u_alu_0 in1", false,-1, 31,0);
        tracep->declBus(c+102,"pipeline_cpu u_alu_0 in2", false,-1, 31,0);
        tracep->declBus(c+96,"pipeline_cpu u_alu_0 alu_control", false,-1, 3,0);
        tracep->declBus(c+70,"pipeline_cpu u_alu_0 result", false,-1, 31,0);
        tracep->declBus(c+123,"pipeline_cpu u_dmem_0 DMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+124,"pipeline_cpu u_dmem_0 DMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBit(c+117,"pipeline_cpu u_dmem_0 clk", false,-1);
        tracep->declBus(c+108,"pipeline_cpu u_dmem_0 addr", false,-1, 9,0);
        tracep->declBus(c+109,"pipeline_cpu u_dmem_0 din", false,-1, 31,0);
        tracep->declBit(c+113,"pipeline_cpu u_dmem_0 mem_read", false,-1);
        tracep->declBit(c+114,"pipeline_cpu u_dmem_0 mem_write", false,-1);
        tracep->declBit(c+115,"pipeline_cpu u_dmem_0 notsigned", false,-1);
        tracep->declBus(c+116,"pipeline_cpu u_dmem_0 size", false,-1, 1,0);
        tracep->declBus(c+110,"pipeline_cpu u_dmem_0 dout", false,-1, 31,0);
    }
}

void Vpipeline_cpu::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vpipeline_cpu::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vpipeline_cpu::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->pipeline_cpu__DOT__pc_curr),32);
        tracep->fullIData(oldp+3,(((IData)(4U) + vlTOPp->pipeline_cpu__DOT__pc_curr)),32);
        tracep->fullIData(oldp+4,((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                   + vlTOPp->pipeline_cpu__DOT__imm32_J)),32);
        tracep->fullSData(oldp+5,((0x3ffU & (vlTOPp->pipeline_cpu__DOT__pc_curr 
                                             >> 2U))),10);
        tracep->fullIData(oldp+6,(vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__data
                                  [(0x3ffU & (vlTOPp->pipeline_cpu__DOT__pc_curr 
                                              >> 2U))]),32);
        tracep->fullWData(oldp+7,(vlTOPp->pipeline_cpu__DOT__id),96);
        tracep->fullCData(oldp+10,((0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U])),7);
        tracep->fullCData(oldp+11,(vlTOPp->pipeline_cpu__DOT__branch),4);
        tracep->fullCData(oldp+12,((((((3U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                       | (0x23U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                      | (0x13U == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])))
                                     ? 3U : (((0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                              | (0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])))
                                              ? 1U : 0U))),2);
        tracep->fullBit(oldp+13,((3U == (0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullCData(oldp+14,(vlTOPp->pipeline_cpu__DOT__alu_op),2);
        tracep->fullBit(oldp+15,((0x23U == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullBit(oldp+16,(((((((((0x33U == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                        | (0x13U == 
                                           (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                       | (3U == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                     | (0x37U == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                    | (IData)(vlTOPp->pipeline_cpu__DOT__isCompare)) 
                                   | (0x6fU == (0x7fU 
                                                & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                  | (0x67U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U])))));
        tracep->fullCData(oldp+17,((0x7fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 7U) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 0x19U)))),7);
        tracep->fullCData(oldp+18,((7U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                           << 0x14U) 
                                          | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                             >> 0xcU)))),3);
        tracep->fullBit(oldp+19,((((((3U == (0x7fU 
                                             & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                     & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                        >> 0xeU)) | 
                                    ((0x33U == (0x7fU 
                                                & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                     & (3U == (7U & 
                                               ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0x14U) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0xcU)))))) 
                                   | ((0x13U == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                      & (3U == (7U 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0x14U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0xcU)))))) 
                                  | ((0x63U == (0x7fU 
                                                & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                     & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                        >> 0xdU)))));
        tracep->fullCData(oldp+20,((3U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                           << 0x14U) 
                                          | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                             >> 0xcU)))),2);
        tracep->fullBit(oldp+21,((0x37U == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullBit(oldp+22,((0x17U == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullBit(oldp+23,(vlTOPp->pipeline_cpu__DOT__isCompare));
        tracep->fullBit(oldp+24,((0x6fU == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullBit(oldp+25,((0x67U == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
        tracep->fullIData(oldp+26,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                     >> 0xbU)))) 
                                      << 0xcU)) | (IData)(vlTOPp->pipeline_cpu__DOT__imm12))),32);
        tracep->fullIData(oldp+27,(((0xffffe000U & 
                                     ((- (IData)((1U 
                                                  & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                     >> 0xbU)))) 
                                      << 0xdU)) | ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                   << 1U))),32);
        tracep->fullSData(oldp+28,(vlTOPp->pipeline_cpu__DOT__imm12),12);
        tracep->fullIData(oldp+29,((0xfffff000U & vlTOPp->pipeline_cpu__DOT__id[1U])),32);
        tracep->fullIData(oldp+30,(vlTOPp->pipeline_cpu__DOT__imm32_J),32);
        tracep->fullCData(oldp+31,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 0x11U) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 0xfU)))),5);
        tracep->fullCData(oldp+32,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 0xcU) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 0x14U)))),5);
        tracep->fullCData(oldp+33,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 0x19U) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 7U)))),5);
        tracep->fullIData(oldp+34,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[0]),32);
        tracep->fullIData(oldp+35,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[1]),32);
        tracep->fullIData(oldp+36,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[2]),32);
        tracep->fullIData(oldp+37,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[3]),32);
        tracep->fullIData(oldp+38,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[4]),32);
        tracep->fullIData(oldp+39,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[5]),32);
        tracep->fullIData(oldp+40,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[6]),32);
        tracep->fullIData(oldp+41,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[7]),32);
        tracep->fullIData(oldp+42,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[8]),32);
        tracep->fullIData(oldp+43,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[9]),32);
        tracep->fullIData(oldp+44,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[10]),32);
        tracep->fullIData(oldp+45,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[11]),32);
        tracep->fullIData(oldp+46,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[12]),32);
        tracep->fullIData(oldp+47,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[13]),32);
        tracep->fullIData(oldp+48,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[14]),32);
        tracep->fullIData(oldp+49,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[15]),32);
        tracep->fullIData(oldp+50,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[16]),32);
        tracep->fullIData(oldp+51,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[17]),32);
        tracep->fullIData(oldp+52,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[18]),32);
        tracep->fullIData(oldp+53,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[19]),32);
        tracep->fullIData(oldp+54,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[20]),32);
        tracep->fullIData(oldp+55,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[21]),32);
        tracep->fullIData(oldp+56,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[22]),32);
        tracep->fullIData(oldp+57,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[23]),32);
        tracep->fullIData(oldp+58,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[24]),32);
        tracep->fullIData(oldp+59,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[25]),32);
        tracep->fullIData(oldp+60,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[26]),32);
        tracep->fullIData(oldp+61,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[27]),32);
        tracep->fullIData(oldp+62,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[28]),32);
        tracep->fullIData(oldp+63,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[29]),32);
        tracep->fullIData(oldp+64,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[30]),32);
        tracep->fullIData(oldp+65,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[31]),32);
        tracep->fullBit(oldp+66,((1U & (~ (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use)))));
        tracep->fullIData(oldp+67,((((vlTOPp->pipeline_cpu__DOT__ex[8U] 
                                      << 0xcU) | (vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                                  >> 0x14U)) 
                                    + (0xfffffffeU 
                                       & ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                           << 0xdU) 
                                          | (0x1ffeU 
                                             & (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                >> 0x13U)))))),32);
        tracep->fullCData(oldp+68,(vlTOPp->pipeline_cpu__DOT__pc_next_sel),2);
        tracep->fullBit(oldp+69,(vlTOPp->pipeline_cpu__DOT__branch_taken));
        tracep->fullIData(oldp+70,(vlTOPp->pipeline_cpu__DOT__alu_result),32);
        tracep->fullWData(oldp+71,(vlTOPp->pipeline_cpu__DOT__ex),276);
        tracep->fullWData(oldp+80,(vlTOPp->pipeline_cpu__DOT__mem),176);
        tracep->fullWData(oldp+86,(vlTOPp->pipeline_cpu__DOT__wb),171);
        tracep->fullBit(oldp+92,(vlTOPp->pipeline_cpu__DOT__stall_by_load_use));
        tracep->fullBit(oldp+93,(((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+94,((1U & (((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                          ? 1U : 0U) 
                                        | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                           >> 3U)))));
        tracep->fullIData(oldp+95,(vlTOPp->pipeline_cpu__DOT__rd_din),32);
        tracep->fullCData(oldp+96,(vlTOPp->pipeline_cpu__DOT__alu_control),4);
        tracep->fullCData(oldp+97,(vlTOPp->pipeline_cpu__DOT__forward_a),2);
        tracep->fullCData(oldp+98,(vlTOPp->pipeline_cpu__DOT__forward_b),2);
        tracep->fullIData(oldp+99,(vlTOPp->pipeline_cpu__DOT__alu_fwd_in1),32);
        tracep->fullIData(oldp+100,(vlTOPp->pipeline_cpu__DOT__alu_fwd_in2),32);
        tracep->fullIData(oldp+101,(vlTOPp->pipeline_cpu__DOT__alu_in1),32);
        tracep->fullIData(oldp+102,(vlTOPp->pipeline_cpu__DOT__alu_in2),32);
        tracep->fullIData(oldp+103,((vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                     - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2)),32);
        tracep->fullBit(oldp+104,(((0U == (vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                           - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2))
                                    ? 1U : 0U)));
        tracep->fullBit(oldp+105,((1U & ((vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                          - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2) 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+106,(vlTOPp->pipeline_cpu__DOT__bu_unsigned_comparison));
        tracep->fullIData(oldp+107,((1U & (vlTOPp->pipeline_cpu__DOT__alu_result 
                                           >> 0x1fU))),32);
        tracep->fullSData(oldp+108,((0x3ffU & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                << 0xeU) 
                                               | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                  >> 0x12U)))),10);
        tracep->fullIData(oldp+109,(((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                      << 0x10U) | (
                                                   vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                   >> 0x10U))),32);
        tracep->fullIData(oldp+110,(vlTOPp->pipeline_cpu__DOT__dmem_dout),32);
        tracep->fullCData(oldp+111,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                               << 0x1aU) 
                                              | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                 >> 6U)))),5);
        tracep->fullBit(oldp+112,((1U & (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                         >> 5U))));
        tracep->fullBit(oldp+113,((1U & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                         >> 0xfU))));
        tracep->fullBit(oldp+114,((1U & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                         >> 0xeU))));
        tracep->fullBit(oldp+115,((1U & (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                         >> 6U))));
        tracep->fullCData(oldp+116,((3U & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                            << 0x1cU) 
                                           | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                              >> 4U)))),2);
        tracep->fullBit(oldp+117,(vlTOPp->clk));
        tracep->fullBit(oldp+118,(vlTOPp->reset_b));
        tracep->fullIData(oldp+119,(((3U == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
                                      ? (((vlTOPp->pipeline_cpu__DOT__ex[8U] 
                                           << 0xcU) 
                                          | (vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                             >> 0x14U)) 
                                         + (0xfffffffeU 
                                            & ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                << 0xdU) 
                                               | (0x1ffeU 
                                                  & (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     >> 0x13U)))))
                                      : ((2U == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
                                          ? (vlTOPp->pipeline_cpu__DOT__id[2U] 
                                             + vlTOPp->pipeline_cpu__DOT__imm32_J)
                                          : ((1U == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
                                              ? vlTOPp->pipeline_cpu__DOT__alu_result
                                              : ((IData)(4U) 
                                                 + vlTOPp->pipeline_cpu__DOT__pc_curr))))),32);
        tracep->fullBit(oldp+120,((1U & ((((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                            ? 1U : 0U) 
                                          | (0x6fU 
                                             == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                         | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                            >> 3U)))));
        tracep->fullIData(oldp+121,((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                       >> 5U) & ((0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                      << 0x11U) 
                                                     | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                        >> 0xfU))) 
                                                 == 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U)))))
                                      ? vlTOPp->pipeline_cpu__DOT__rd_din
                                      : ((0U != (0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x11U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xfU))))
                                          ? vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data
                                         [(0x1fU & 
                                           ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                             << 0x11U) 
                                            | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                               >> 0xfU)))]
                                          : 0U))),32);
        tracep->fullIData(oldp+122,((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                       >> 5U) & ((0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                      << 0xcU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                        >> 0x14U))) 
                                                 == 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U)))))
                                      ? vlTOPp->pipeline_cpu__DOT__rd_din
                                      : ((0U != (0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0x14U))))
                                          ? vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data
                                         [(0x1fU & 
                                           ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                             << 0xcU) 
                                            | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                               >> 0x14U)))]
                                          : 0U))),32);
        tracep->fullIData(oldp+123,(0x400U),32);
        tracep->fullIData(oldp+124,(0xaU),32);
        tracep->fullIData(oldp+125,(0x20U),32);
    }
}
