// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsingle_cycle_cpu__Syms.h"


void Vsingle_cycle_cpu::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vsingle_cycle_cpu::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+1,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[0]),32);
            tracep->chgIData(oldp+2,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[1]),32);
            tracep->chgIData(oldp+3,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[2]),32);
            tracep->chgIData(oldp+4,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[3]),32);
            tracep->chgIData(oldp+5,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[4]),32);
            tracep->chgIData(oldp+6,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[5]),32);
            tracep->chgIData(oldp+7,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[6]),32);
            tracep->chgIData(oldp+8,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[7]),32);
            tracep->chgIData(oldp+9,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[8]),32);
            tracep->chgIData(oldp+10,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[9]),32);
            tracep->chgIData(oldp+11,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[10]),32);
            tracep->chgIData(oldp+12,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[11]),32);
            tracep->chgIData(oldp+13,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[12]),32);
            tracep->chgIData(oldp+14,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[13]),32);
            tracep->chgIData(oldp+15,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[14]),32);
            tracep->chgIData(oldp+16,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[15]),32);
            tracep->chgIData(oldp+17,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[16]),32);
            tracep->chgIData(oldp+18,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[17]),32);
            tracep->chgIData(oldp+19,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[18]),32);
            tracep->chgIData(oldp+20,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[19]),32);
            tracep->chgIData(oldp+21,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[20]),32);
            tracep->chgIData(oldp+22,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[21]),32);
            tracep->chgIData(oldp+23,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[22]),32);
            tracep->chgIData(oldp+24,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[23]),32);
            tracep->chgIData(oldp+25,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[24]),32);
            tracep->chgIData(oldp+26,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[25]),32);
            tracep->chgIData(oldp+27,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[26]),32);
            tracep->chgIData(oldp+28,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[27]),32);
            tracep->chgIData(oldp+29,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[28]),32);
            tracep->chgIData(oldp+30,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[29]),32);
            tracep->chgIData(oldp+31,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[30]),32);
            tracep->chgIData(oldp+32,(vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgSData(oldp+33,((0x3ffU & (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                                 >> 2U))),10);
            tracep->chgIData(oldp+34,(vlTOPp->single_cycle_cpu__DOT__inst),32);
            tracep->chgCData(oldp+35,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+36,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+37,((0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                >> 7U))),5);
            tracep->chgIData(oldp+38,((((0x6fU == (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                        | (0x67U == 
                                           (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)))
                                        ? ((IData)(4U) 
                                           + vlTOPp->single_cycle_cpu__DOT__pc_curr)
                                        : ((IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)
                                            ? (1U & 
                                               (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                >> 0x1fU))
                                            : ((0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->single_cycle_cpu__DOT__inst))
                                                ? (0xfffff000U 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))
                                                    ? vlTOPp->single_cycle_cpu__DOT__dmem_dout
                                                    : vlTOPp->single_cycle_cpu__DOT__alu_result))))),32);
            tracep->chgBit(oldp+39,(((((((((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                           | (0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                          | (3U == 
                                             (0x7fU 
                                              & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                         | (0x17U == 
                                            (0x7fU 
                                             & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                        | (0x37U == 
                                           (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                       | (IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst)))));
            tracep->chgIData(oldp+40,(vlTOPp->single_cycle_cpu__DOT__rs2_dout),32);
            tracep->chgIData(oldp+41,(vlTOPp->single_cycle_cpu__DOT__alu_in1),32);
            tracep->chgIData(oldp+42,(vlTOPp->single_cycle_cpu__DOT__alu_in2),32);
            tracep->chgCData(oldp+43,(vlTOPp->single_cycle_cpu__DOT__alu_control),4);
            tracep->chgIData(oldp+44,(vlTOPp->single_cycle_cpu__DOT__alu_result),32);
            tracep->chgBit(oldp+45,((1U & (~ (IData)(
                                                     (0U 
                                                      != vlTOPp->single_cycle_cpu__DOT__alu_result))))));
            tracep->chgBit(oldp+46,((1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                           >> 0x1fU))));
            tracep->chgSData(oldp+47,((0x3ffU & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                 >> 2U))),10);
            tracep->chgIData(oldp+48,(vlTOPp->single_cycle_cpu__DOT__dmem_dout),32);
            tracep->chgBit(oldp+49,((3U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgBit(oldp+50,((0x23U == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgCData(oldp+51,((0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)),7);
            tracep->chgCData(oldp+52,(vlTOPp->single_cycle_cpu__DOT__branch),6);
            tracep->chgCData(oldp+53,(vlTOPp->single_cycle_cpu__DOT__alu_src),2);
            tracep->chgCData(oldp+54,(vlTOPp->single_cycle_cpu__DOT__alu_op),2);
            tracep->chgCData(oldp+55,((7U & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+56,((3U & (vlTOPp->single_cycle_cpu__DOT__inst 
                                             >> 0xcU))),2);
            tracep->chgBit(oldp+57,(vlTOPp->single_cycle_cpu__DOT__notsigned));
            tracep->chgBit(oldp+58,((0x37U == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgBit(oldp+59,((0x17U == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgBit(oldp+60,(vlTOPp->single_cycle_cpu__DOT__isCompare));
            tracep->chgBit(oldp+61,((0x6fU == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgBit(oldp+62,((0x67U == (0x7fU 
                                               & vlTOPp->single_cycle_cpu__DOT__inst))));
            tracep->chgCData(oldp+63,((0x7fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                >> 0x19U))),7);
            tracep->chgIData(oldp+64,(vlTOPp->single_cycle_cpu__DOT__imm32),32);
            tracep->chgIData(oldp+65,((0xfffffffeU 
                                       & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                          << 1U))),32);
            tracep->chgSData(oldp+66,(vlTOPp->single_cycle_cpu__DOT__imm12),12);
            tracep->chgIData(oldp+67,((0xfffff000U 
                                       & vlTOPp->single_cycle_cpu__DOT__inst)),32);
            tracep->chgIData(oldp+68,(((0xfff00000U 
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
                                                   >> 0x14U)))))),32);
            tracep->chgIData(oldp+69,(vlTOPp->single_cycle_cpu__DOT__pc_curr),32);
            tracep->chgIData(oldp+70,(((3U == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
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
                                            : ((1U 
                                                == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                                ? vlTOPp->single_cycle_cpu__DOT__alu_result
                                                : ((IData)(4U) 
                                                   + vlTOPp->single_cycle_cpu__DOT__pc_curr))))),32);
            tracep->chgCData(oldp+71,(vlTOPp->single_cycle_cpu__DOT__pc_next_sel),2);
            tracep->chgIData(oldp+72,(((IData)(4U) 
                                       + vlTOPp->single_cycle_cpu__DOT__pc_curr)),32);
            tracep->chgIData(oldp+73,((vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                       + (0xfffffffeU 
                                          & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                             << 1U)))),32);
            tracep->chgIData(oldp+74,((vlTOPp->single_cycle_cpu__DOT__pc_curr 
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
            tracep->chgIData(oldp+75,((1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                             >> 0x1fU))),32);
        }
        tracep->chgBit(oldp+76,(vlTOPp->clk));
        tracep->chgBit(oldp+77,(vlTOPp->reset_b));
        tracep->chgIData(oldp+78,(((0U != (0x1fU & 
                                           (vlTOPp->single_cycle_cpu__DOT__inst 
                                            >> 0xfU)))
                                    ? vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data
                                   [(0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                                              >> 0xfU))]
                                    : 0U)),32);
    }
}

void Vsingle_cycle_cpu::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = static_cast<Vsingle_cycle_cpu__Syms*>(userp);
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
