// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsingle_cycle_cpu__Syms.h"


//======================

void Vsingle_cycle_cpu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vsingle_cycle_cpu::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vsingle_cycle_cpu::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vsingle_cycle_cpu::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vsingle_cycle_cpu::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+77,"clk", false,-1);
        tracep->declBit(c+78,"reset_b", false,-1);
        tracep->declBus(c+80,"single_cycle_cpu IMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+81,"single_cycle_cpu IMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+82,"single_cycle_cpu REG_WIDTH", false,-1, 31,0);
        tracep->declBus(c+80,"single_cycle_cpu DMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+81,"single_cycle_cpu DMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBit(c+77,"single_cycle_cpu clk", false,-1);
        tracep->declBit(c+78,"single_cycle_cpu reset_b", false,-1);
        tracep->declBus(c+34,"single_cycle_cpu imem_addr", false,-1, 9,0);
        tracep->declBus(c+35,"single_cycle_cpu inst", false,-1, 31,0);
        tracep->declBus(c+36,"single_cycle_cpu rs1", false,-1, 4,0);
        tracep->declBus(c+37,"single_cycle_cpu rs2", false,-1, 4,0);
        tracep->declBus(c+38,"single_cycle_cpu rd", false,-1, 4,0);
        tracep->declBus(c+39,"single_cycle_cpu rd_din", false,-1, 31,0);
        tracep->declBit(c+40,"single_cycle_cpu reg_write", false,-1);
        tracep->declBus(c+79,"single_cycle_cpu rs1_dout", false,-1, 31,0);
        tracep->declBus(c+41,"single_cycle_cpu rs2_dout", false,-1, 31,0);
        tracep->declBus(c+42,"single_cycle_cpu alu_in1", false,-1, 31,0);
        tracep->declBus(c+43,"single_cycle_cpu alu_in2", false,-1, 31,0);
        tracep->declBus(c+44,"single_cycle_cpu alu_control", false,-1, 3,0);
        tracep->declBus(c+45,"single_cycle_cpu alu_result", false,-1, 31,0);
        tracep->declBit(c+46,"single_cycle_cpu alu_zero", false,-1);
        tracep->declBit(c+47,"single_cycle_cpu alu_sign", false,-1);
        tracep->declBus(c+48,"single_cycle_cpu dmem_addr", false,-1, 9,0);
        tracep->declBus(c+41,"single_cycle_cpu dmem_din", false,-1, 31,0);
        tracep->declBus(c+49,"single_cycle_cpu dmem_dout", false,-1, 31,0);
        tracep->declBit(c+50,"single_cycle_cpu mem_read", false,-1);
        tracep->declBit(c+51,"single_cycle_cpu mem_write", false,-1);
        tracep->declBus(c+52,"single_cycle_cpu opcode", false,-1, 6,0);
        tracep->declBus(c+53,"single_cycle_cpu branch", false,-1, 5,0);
        tracep->declBus(c+54,"single_cycle_cpu alu_src", false,-1, 1,0);
        tracep->declBit(c+50,"single_cycle_cpu mem_to_reg", false,-1);
        tracep->declBus(c+55,"single_cycle_cpu alu_op", false,-1, 1,0);
        tracep->declBus(c+56,"single_cycle_cpu funct3", false,-1, 2,0);
        tracep->declBus(c+57,"single_cycle_cpu size", false,-1, 1,0);
        tracep->declBit(c+58,"single_cycle_cpu notsigned", false,-1);
        tracep->declBit(c+59,"single_cycle_cpu isLUI", false,-1);
        tracep->declBit(c+60,"single_cycle_cpu isAUIPC", false,-1);
        tracep->declBit(c+61,"single_cycle_cpu isCompare", false,-1);
        tracep->declBit(c+62,"single_cycle_cpu isJAL", false,-1);
        tracep->declBit(c+63,"single_cycle_cpu isJALR", false,-1);
        tracep->declBus(c+64,"single_cycle_cpu funct7", false,-1, 6,0);
        tracep->declBus(c+65,"single_cycle_cpu imm32", false,-1, 31,0);
        tracep->declBus(c+66,"single_cycle_cpu imm32_branch", false,-1, 31,0);
        tracep->declBus(c+67,"single_cycle_cpu imm12", false,-1, 11,0);
        tracep->declBus(c+68,"single_cycle_cpu imm32_U", false,-1, 31,0);
        tracep->declBus(c+69,"single_cycle_cpu imm32_J", false,-1, 31,0);
        tracep->declBus(c+70,"single_cycle_cpu pc_curr", false,-1, 31,0);
        tracep->declBus(c+71,"single_cycle_cpu pc_next", false,-1, 31,0);
        tracep->declBus(c+72,"single_cycle_cpu pc_next_sel", false,-1, 1,0);
        tracep->declBus(c+73,"single_cycle_cpu pc_next_plus4", false,-1, 31,0);
        tracep->declBus(c+74,"single_cycle_cpu pc_next_branch", false,-1, 31,0);
        tracep->declBus(c+75,"single_cycle_cpu pc_next_JAL", false,-1, 31,0);
        tracep->declBus(c+76,"single_cycle_cpu comp_result", false,-1, 31,0);
        tracep->declBus(c+80,"single_cycle_cpu u_imem_0 IMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+81,"single_cycle_cpu u_imem_0 IMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+34,"single_cycle_cpu u_imem_0 addr", false,-1, 9,0);
        tracep->declBus(c+35,"single_cycle_cpu u_imem_0 dout", false,-1, 31,0);
        tracep->declBus(c+1,"single_cycle_cpu u_imem_0 unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+82,"single_cycle_cpu u_regfile_0 REG_WIDTH", false,-1, 31,0);
        tracep->declBit(c+77,"single_cycle_cpu u_regfile_0 clk", false,-1);
        tracep->declBus(c+36,"single_cycle_cpu u_regfile_0 rs1", false,-1, 4,0);
        tracep->declBus(c+37,"single_cycle_cpu u_regfile_0 rs2", false,-1, 4,0);
        tracep->declBus(c+38,"single_cycle_cpu u_regfile_0 rd", false,-1, 4,0);
        tracep->declBus(c+39,"single_cycle_cpu u_regfile_0 rd_din", false,-1, 31,0);
        tracep->declBit(c+40,"single_cycle_cpu u_regfile_0 reg_write", false,-1);
        tracep->declBus(c+79,"single_cycle_cpu u_regfile_0 rs1_dout", false,-1, 31,0);
        tracep->declBus(c+41,"single_cycle_cpu u_regfile_0 rs2_dout", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+2+i*1,"single_cycle_cpu u_regfile_0 rf_data", true,(i+0), 31,0);}}
        tracep->declBus(c+82,"single_cycle_cpu u_alu_0 REG_WIDTH", false,-1, 31,0);
        tracep->declBus(c+42,"single_cycle_cpu u_alu_0 in1", false,-1, 31,0);
        tracep->declBus(c+43,"single_cycle_cpu u_alu_0 in2", false,-1, 31,0);
        tracep->declBus(c+44,"single_cycle_cpu u_alu_0 alu_control", false,-1, 3,0);
        tracep->declBus(c+45,"single_cycle_cpu u_alu_0 result", false,-1, 31,0);
        tracep->declBit(c+46,"single_cycle_cpu u_alu_0 zero", false,-1);
        tracep->declBit(c+47,"single_cycle_cpu u_alu_0 sign", false,-1);
        tracep->declBus(c+80,"single_cycle_cpu u_dmem_0 DMEM_DEPTH", false,-1, 31,0);
        tracep->declBus(c+81,"single_cycle_cpu u_dmem_0 DMEM_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBit(c+77,"single_cycle_cpu u_dmem_0 clk", false,-1);
        tracep->declBus(c+48,"single_cycle_cpu u_dmem_0 addr", false,-1, 9,0);
        tracep->declBus(c+41,"single_cycle_cpu u_dmem_0 din", false,-1, 31,0);
        tracep->declBit(c+50,"single_cycle_cpu u_dmem_0 mem_read", false,-1);
        tracep->declBit(c+51,"single_cycle_cpu u_dmem_0 mem_write", false,-1);
        tracep->declBit(c+58,"single_cycle_cpu u_dmem_0 notsigned", false,-1);
        tracep->declBus(c+57,"single_cycle_cpu u_dmem_0 size", false,-1, 1,0);
        tracep->declBus(c+49,"single_cycle_cpu u_dmem_0 dout", false,-1, 31,0);
    }
}

void Vsingle_cycle_cpu::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vsingle_cycle_cpu::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vsingle_cycle_cpu::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[0]),32);
        tracep->fullIData(oldp+3,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[1]),32);
        tracep->fullIData(oldp+4,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[2]),32);
        tracep->fullIData(oldp+5,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[3]),32);
        tracep->fullIData(oldp+6,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[4]),32);
        tracep->fullIData(oldp+7,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[5]),32);
        tracep->fullIData(oldp+8,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[6]),32);
        tracep->fullIData(oldp+9,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[7]),32);
        tracep->fullIData(oldp+10,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[8]),32);
        tracep->fullIData(oldp+11,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[9]),32);
        tracep->fullIData(oldp+12,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[10]),32);
        tracep->fullIData(oldp+13,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[11]),32);
        tracep->fullIData(oldp+14,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[12]),32);
        tracep->fullIData(oldp+15,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[13]),32);
        tracep->fullIData(oldp+16,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[14]),32);
        tracep->fullIData(oldp+17,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[15]),32);
        tracep->fullIData(oldp+18,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[16]),32);
        tracep->fullIData(oldp+19,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[17]),32);
        tracep->fullIData(oldp+20,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[18]),32);
        tracep->fullIData(oldp+21,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[19]),32);
        tracep->fullIData(oldp+22,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[20]),32);
        tracep->fullIData(oldp+23,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[21]),32);
        tracep->fullIData(oldp+24,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[22]),32);
        tracep->fullIData(oldp+25,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[23]),32);
        tracep->fullIData(oldp+26,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[24]),32);
        tracep->fullIData(oldp+27,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[25]),32);
        tracep->fullIData(oldp+28,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[26]),32);
        tracep->fullIData(oldp+29,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[27]),32);
        tracep->fullIData(oldp+30,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[28]),32);
        tracep->fullIData(oldp+31,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[29]),32);
        tracep->fullIData(oldp+32,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[30]),32);
        tracep->fullIData(oldp+33,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[31]),32);
        tracep->fullSData(oldp+34,((0x3ffU & (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                              >> 2U))),10);
        tracep->fullIData(oldp+35,(vlTOPp->single_cycle_cpu__DOT__inst),32);
        tracep->fullCData(oldp+36,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+37,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+38,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 7U))),5);
        tracep->fullIData(oldp+39,((((0x6fU == (0x7fU 
                                                & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst)))
                                     ? ((IData)(4U) 
                                        + vlTOPp->single_cycle_cpu__DOT__pc_curr)
                                     : ((IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)
                                         ? (1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                  >> 0x1fU))
                                         : ((0x37U 
                                             == (0x7fU 
                                                 & vlTOPp->single_cycle_cpu__DOT__inst))
                                             ? (0xfffff000U 
                                                & vlTOPp->single_cycle_cpu__DOT__inst)
                                             : ((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst))
                                                 ? vlTOPp->single_cycle_cpu__DOT__dmem_dout
                                                 : vlTOPp->single_cycle_cpu__DOT__alu_result))))),32);
        tracep->fullBit(oldp+40,(((((((((0x33U == (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                        | (0x13U == 
                                           (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                       | (3U == (0x7fU 
                                                 & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                     | (0x37U == (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                    | (IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)) 
                                   | (0x6fU == (0x7fU 
                                                & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                  | (0x67U == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst)))));
        tracep->fullIData(oldp+41,(vlTOPp->single_cycle_cpu__DOT__rs2_dout),32);
        tracep->fullIData(oldp+42,(vlTOPp->single_cycle_cpu__DOT__alu_in1),32);
        tracep->fullIData(oldp+43,(vlTOPp->single_cycle_cpu__DOT__alu_in2),32);
        tracep->fullCData(oldp+44,(vlTOPp->single_cycle_cpu__DOT__alu_control),4);
        tracep->fullIData(oldp+45,(vlTOPp->single_cycle_cpu__DOT__alu_result),32);
        tracep->fullBit(oldp+46,((1U & (~ (IData)((0U 
                                                   != vlTOPp->single_cycle_cpu__DOT__alu_result))))));
        tracep->fullBit(oldp+47,((1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                        >> 0x1fU))));
        tracep->fullSData(oldp+48,((0x3ffU & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                              >> 2U))),10);
        tracep->fullIData(oldp+49,(vlTOPp->single_cycle_cpu__DOT__dmem_dout),32);
        tracep->fullBit(oldp+50,((3U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullBit(oldp+51,((0x23U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullCData(oldp+52,((0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)),7);
        tracep->fullCData(oldp+53,(vlTOPp->single_cycle_cpu__DOT__branch),6);
        tracep->fullCData(oldp+54,(vlTOPp->single_cycle_cpu__DOT__alu_src),2);
        tracep->fullCData(oldp+55,(vlTOPp->single_cycle_cpu__DOT__alu_op),2);
        tracep->fullCData(oldp+56,((7U & (vlTOPp->single_cycle_cpu__DOT__inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+57,((3U & (vlTOPp->single_cycle_cpu__DOT__inst 
                                          >> 0xcU))),2);
        tracep->fullBit(oldp+58,(vlTOPp->single_cycle_cpu__DOT__notsigned));
        tracep->fullBit(oldp+59,((0x37U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullBit(oldp+60,((0x17U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullBit(oldp+61,(vlTOPp->single_cycle_cpu__DOT__isCompare));
        tracep->fullBit(oldp+62,((0x6fU == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullBit(oldp+63,((0x67U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
        tracep->fullCData(oldp+64,((0x7fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0x19U))),7);
        tracep->fullIData(oldp+65,(vlTOPp->single_cycle_cpu__DOT__imm32),32);
        tracep->fullIData(oldp+66,((0xfffffffeU & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                                   << 1U))),32);
        tracep->fullSData(oldp+67,(vlTOPp->single_cycle_cpu__DOT__imm12),12);
        tracep->fullIData(oldp+68,((0xfffff000U & vlTOPp->single_cycle_cpu__DOT__inst)),32);
        tracep->fullIData(oldp+69,(((0xfff00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                     >> 0x1fU)))) 
                                      << 0x14U)) | 
                                    ((0xff000U & vlTOPp->single_cycle_cpu__DOT__inst) 
                                     | ((0x800U & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                   >> 9U)) 
                                        | (0x7feU & 
                                           (vlTOPp->single_cycle_cpu__DOT__inst 
                                            >> 0x14U)))))),32);
        tracep->fullIData(oldp+70,(vlTOPp->single_cycle_cpu__DOT__pc_curr),32);
        tracep->fullIData(oldp+71,(((3U == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                     ? (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                        + (0xfffffffeU 
                                           & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                              << 1U)))
                                     : ((2U == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                         ? (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                            + ((0xfff00000U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                                  >> 0x1fU)))) 
                                                   << 0x14U)) 
                                               | ((0xff000U 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst) 
                                                  | ((0x800U 
                                                      & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                         >> 9U)) 
                                                     | (0x7feU 
                                                        & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                           >> 0x14U))))))
                                         : ((1U == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                             ? vlTOPp->single_cycle_cpu__DOT__alu_result
                                             : ((IData)(4U) 
                                                + vlTOPp->single_cycle_cpu__DOT__pc_curr))))),32);
        tracep->fullCData(oldp+72,(vlTOPp->single_cycle_cpu__DOT__pc_next_sel),2);
        tracep->fullIData(oldp+73,(((IData)(4U) + vlTOPp->single_cycle_cpu__DOT__pc_curr)),32);
        tracep->fullIData(oldp+74,((vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                    + (0xfffffffeU 
                                       & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                          << 1U)))),32);
        tracep->fullIData(oldp+75,((vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                    + ((0xfff00000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                          >> 0x1fU)))) 
                                           << 0x14U)) 
                                       | ((0xff000U 
                                           & vlTOPp->single_cycle_cpu__DOT__inst) 
                                          | ((0x800U 
                                              & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                 >> 9U)) 
                                             | (0x7feU 
                                                & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                   >> 0x14U))))))),32);
        tracep->fullIData(oldp+76,((1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                          >> 0x1fU))),32);
        tracep->fullBit(oldp+77,(vlTOPp->clk));
        tracep->fullBit(oldp+78,(vlTOPp->reset_b));
        tracep->fullIData(oldp+79,(((0U != (0x1fU & 
                                            (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0xfU)))
                                     ? vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data
                                    [(0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                               >> 0xfU))]
                                     : 0U)),32);
        tracep->fullIData(oldp+80,(0x400U),32);
        tracep->fullIData(oldp+81,(0xaU),32);
        tracep->fullIData(oldp+82,(0x20U),32);
    }
}
