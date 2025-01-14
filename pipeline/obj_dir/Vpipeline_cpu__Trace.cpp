// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpipeline_cpu__Syms.h"


void Vpipeline_cpu::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vpipeline_cpu::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+1,(vlTOPp->pipeline_cpu__DOT__pc_curr),32);
            tracep->chgIData(oldp+2,(((IData)(4U) + vlTOPp->pipeline_cpu__DOT__pc_curr)),32);
            tracep->chgIData(oldp+3,((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                      + vlTOPp->pipeline_cpu__DOT__imm32_J)),32);
            tracep->chgSData(oldp+4,((0x3ffU & (vlTOPp->pipeline_cpu__DOT__pc_curr 
                                                >> 2U))),10);
            tracep->chgIData(oldp+5,(vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__data
                                     [(0x3ffU & (vlTOPp->pipeline_cpu__DOT__pc_curr 
                                                 >> 2U))]),32);
            tracep->chgWData(oldp+6,(vlTOPp->pipeline_cpu__DOT__id),96);
            tracep->chgCData(oldp+9,((0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U])),7);
            tracep->chgCData(oldp+10,(vlTOPp->pipeline_cpu__DOT__branch),4);
            tracep->chgCData(oldp+11,((((((3U == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                          | (0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                         | (0x13U == 
                                            (0x7fU 
                                             & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                        | (0x67U == 
                                           (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U])))
                                        ? 3U : (((0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                                 | (0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->pipeline_cpu__DOT__id[1U])))
                                                 ? 1U
                                                 : 0U))),2);
            tracep->chgBit(oldp+12,((3U == (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgCData(oldp+13,(vlTOPp->pipeline_cpu__DOT__alu_op),2);
            tracep->chgBit(oldp+14,((0x23U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgBit(oldp+15,(((((((((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                           | (0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                          | (3U == 
                                             (0x7fU 
                                              & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                         | (0x17U == 
                                            (0x7fU 
                                             & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                        | (0x37U == 
                                           (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                       | (IData)(vlTOPp->pipeline_cpu__DOT__isCompare)) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])))));
            tracep->chgCData(oldp+16,((0x7fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 7U) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0x19U)))),7);
            tracep->chgCData(oldp+17,((7U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 0x14U) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 0xcU)))),3);
            tracep->chgBit(oldp+18,((((((3U == (0x7fU 
                                                & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                        & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                           >> 0xeU)) 
                                       | ((0x33U == 
                                           (0x7fU & 
                                            vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                          & (3U == 
                                             (7U & 
                                              ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                << 0x14U) 
                                               | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                  >> 0xcU)))))) 
                                      | ((0x13U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         & (3U == (7U 
                                                   & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                         >> 0xcU)))))) 
                                     | ((0x63U == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                        & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                           >> 0xdU)))));
            tracep->chgCData(oldp+19,((3U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                              << 0x14U) 
                                             | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                >> 0xcU)))),2);
            tracep->chgBit(oldp+20,((0x37U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgBit(oldp+21,((0x17U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgBit(oldp+22,(vlTOPp->pipeline_cpu__DOT__isCompare));
            tracep->chgBit(oldp+23,((0x6fU == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgBit(oldp+24,((0x67U == (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U]))));
            tracep->chgIData(oldp+25,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                          >> 0xbU)))) 
                                           << 0xcU)) 
                                       | (IData)(vlTOPp->pipeline_cpu__DOT__imm12))),32);
            tracep->chgIData(oldp+26,(((0xffffe000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                          >> 0xbU)))) 
                                           << 0xdU)) 
                                       | ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                          << 1U))),32);
            tracep->chgSData(oldp+27,(vlTOPp->pipeline_cpu__DOT__imm12),12);
            tracep->chgIData(oldp+28,((0xfffff000U 
                                       & vlTOPp->pipeline_cpu__DOT__id[1U])),32);
            tracep->chgIData(oldp+29,(vlTOPp->pipeline_cpu__DOT__imm32_J),32);
            tracep->chgCData(oldp+30,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0x11U) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0xfU)))),5);
            tracep->chgCData(oldp+31,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0xcU) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0x14U)))),5);
            tracep->chgCData(oldp+32,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0x19U) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 7U)))),5);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+33,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[0]),32);
            tracep->chgIData(oldp+34,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[1]),32);
            tracep->chgIData(oldp+35,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[2]),32);
            tracep->chgIData(oldp+36,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[3]),32);
            tracep->chgIData(oldp+37,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[4]),32);
            tracep->chgIData(oldp+38,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[5]),32);
            tracep->chgIData(oldp+39,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[6]),32);
            tracep->chgIData(oldp+40,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[7]),32);
            tracep->chgIData(oldp+41,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[8]),32);
            tracep->chgIData(oldp+42,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[9]),32);
            tracep->chgIData(oldp+43,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[10]),32);
            tracep->chgIData(oldp+44,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[11]),32);
            tracep->chgIData(oldp+45,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[12]),32);
            tracep->chgIData(oldp+46,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[13]),32);
            tracep->chgIData(oldp+47,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[14]),32);
            tracep->chgIData(oldp+48,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[15]),32);
            tracep->chgIData(oldp+49,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[16]),32);
            tracep->chgIData(oldp+50,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[17]),32);
            tracep->chgIData(oldp+51,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[18]),32);
            tracep->chgIData(oldp+52,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[19]),32);
            tracep->chgIData(oldp+53,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[20]),32);
            tracep->chgIData(oldp+54,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[21]),32);
            tracep->chgIData(oldp+55,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[22]),32);
            tracep->chgIData(oldp+56,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[23]),32);
            tracep->chgIData(oldp+57,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[24]),32);
            tracep->chgIData(oldp+58,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[25]),32);
            tracep->chgIData(oldp+59,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[26]),32);
            tracep->chgIData(oldp+60,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[27]),32);
            tracep->chgIData(oldp+61,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[28]),32);
            tracep->chgIData(oldp+62,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[29]),32);
            tracep->chgIData(oldp+63,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[30]),32);
            tracep->chgIData(oldp+64,(vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+65,((1U & (~ (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use)))));
            tracep->chgIData(oldp+66,((((vlTOPp->pipeline_cpu__DOT__ex[8U] 
                                         << 0xcU) | 
                                        (vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                         >> 0x14U)) 
                                       + (0xfffffffeU 
                                          & ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                              << 0xdU) 
                                             | (0x1ffeU 
                                                & (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                   >> 0x13U)))))),32);
            tracep->chgCData(oldp+67,(vlTOPp->pipeline_cpu__DOT__pc_next_sel),2);
            tracep->chgBit(oldp+68,(vlTOPp->pipeline_cpu__DOT__branch_taken));
            tracep->chgIData(oldp+69,(vlTOPp->pipeline_cpu__DOT__alu_result),32);
            tracep->chgWData(oldp+70,(vlTOPp->pipeline_cpu__DOT__ex),276);
            tracep->chgWData(oldp+79,(vlTOPp->pipeline_cpu__DOT__mem),176);
            tracep->chgWData(oldp+85,(vlTOPp->pipeline_cpu__DOT__wb),171);
            tracep->chgBit(oldp+91,(vlTOPp->pipeline_cpu__DOT__stall_by_load_use));
            tracep->chgBit(oldp+92,(((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                      ? 1U : 0U)));
            tracep->chgBit(oldp+93,((1U & (((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                             ? 1U : 0U) 
                                           | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                              >> 3U)))));
            tracep->chgIData(oldp+94,(vlTOPp->pipeline_cpu__DOT__rd_din),32);
            tracep->chgCData(oldp+95,(vlTOPp->pipeline_cpu__DOT__alu_control),4);
            tracep->chgCData(oldp+96,(vlTOPp->pipeline_cpu__DOT__forward_a),2);
            tracep->chgCData(oldp+97,(vlTOPp->pipeline_cpu__DOT__forward_b),2);
            tracep->chgIData(oldp+98,(vlTOPp->pipeline_cpu__DOT__alu_fwd_in1),32);
            tracep->chgIData(oldp+99,(vlTOPp->pipeline_cpu__DOT__alu_fwd_in2),32);
            tracep->chgIData(oldp+100,(vlTOPp->pipeline_cpu__DOT__alu_in1),32);
            tracep->chgIData(oldp+101,(vlTOPp->pipeline_cpu__DOT__alu_in2),32);
            tracep->chgIData(oldp+102,((vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                        - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2)),32);
            tracep->chgBit(oldp+103,(((0U == (vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                              - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2))
                                       ? 1U : 0U)));
            tracep->chgBit(oldp+104,((1U & ((vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                             - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2) 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+105,(vlTOPp->pipeline_cpu__DOT__bu_unsigned_comparison));
            tracep->chgIData(oldp+106,((1U & (vlTOPp->pipeline_cpu__DOT__alu_result 
                                              >> 0x1fU))),32);
            tracep->chgSData(oldp+107,((0x3ffU & ((
                                                   vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                   << 0xeU) 
                                                  | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                     >> 0x12U)))),10);
            tracep->chgIData(oldp+108,(((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                         << 0x10U) 
                                        | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                           >> 0x10U))),32);
            tracep->chgIData(oldp+109,(vlTOPp->pipeline_cpu__DOT__dmem_dout),32);
            tracep->chgCData(oldp+110,((0x1fU & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                  << 0x1aU) 
                                                 | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                    >> 6U)))),5);
            tracep->chgBit(oldp+111,((1U & (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                            >> 5U))));
            tracep->chgBit(oldp+112,((1U & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                            >> 0xfU))));
            tracep->chgBit(oldp+113,((1U & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                            >> 0xeU))));
            tracep->chgBit(oldp+114,((1U & (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                            >> 6U))));
            tracep->chgCData(oldp+115,((3U & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                               << 0x1cU) 
                                              | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                 >> 4U)))),2);
        }
        tracep->chgBit(oldp+116,(vlTOPp->clk));
        tracep->chgBit(oldp+117,(vlTOPp->reset_b));
        tracep->chgIData(oldp+118,(((3U == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
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
        tracep->chgBit(oldp+119,((1U & ((((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                           ? 1U : 0U) 
                                         | (0x6fU == 
                                            (0x7fU 
                                             & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                        | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                           >> 3U)))));
        tracep->chgIData(oldp+120,((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
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
                                        [(0x1fU & (
                                                   (vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0xfU)))]
                                         : 0U))),32);
        tracep->chgIData(oldp+121,((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
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
                                        [(0x1fU & (
                                                   (vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0x14U)))]
                                         : 0U))),32);
    }
}

void Vpipeline_cpu::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = static_cast<Vpipeline_cpu__Syms*>(userp);
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
