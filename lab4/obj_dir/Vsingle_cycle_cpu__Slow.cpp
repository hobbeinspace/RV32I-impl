// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsingle_cycle_cpu.h for the primary calling header

#include "Vsingle_cycle_cpu.h"
#include "Vsingle_cycle_cpu__Syms.h"

//==========

VL_CTOR_IMP(Vsingle_cycle_cpu) {
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = __VlSymsp = new Vsingle_cycle_cpu__Syms(this, name());
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsingle_cycle_cpu::__Vconfigure(Vsingle_cycle_cpu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vsingle_cycle_cpu::~Vsingle_cycle_cpu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vsingle_cycle_cpu::_initial__TOP__1(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_initial__TOP__1\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_READMEM_N(true, 32, 1024, 0, std::string("dmem.mem")
                 , vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                 , 0, ~0ULL);
    vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x400U, vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i)) {
        vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__data[(0x3ffU 
                                                            & vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i)] = 0U;
        vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i);
    }
    VL_READMEM_N(false, 32, 1024, 0, std::string("imem.mem")
                 , vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__data
                 , 0, ~0ULL);
}

void Vsingle_cycle_cpu::_settle__TOP__4(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_settle__TOP__4\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->single_cycle_cpu__DOT__inst = vlTOPp->single_cycle_cpu__DOT__u_imem_0__DOT__data
        [(0x3ffU & (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                    >> 2U))];
    vlTOPp->single_cycle_cpu__DOT__isCompare = (((0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 | (0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                                & ((2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU))) 
                                                   | (3U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                          >> 0xcU)))));
    vlTOPp->single_cycle_cpu__DOT__alu_in1 = ((0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst))
                                               ? vlTOPp->single_cycle_cpu__DOT__pc_curr
                                               : ((0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                       >> 0xfU)))
                                                   ? 
                                                  vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data
                                                  [
                                                  (0x1fU 
                                                   & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                      >> 0xfU))]
                                                   : 0U));
    vlTOPp->single_cycle_cpu__DOT__alu_src = (((((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 | (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                                | (0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                               | (0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)))
                                               ? 3U
                                               : ((
                                                   (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                   | (0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->single_cycle_cpu__DOT__inst)))
                                                   ? 1U
                                                   : 0U));
    vlTOPp->single_cycle_cpu__DOT__alu_op = ((1U & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_op)) 
                                             | ((((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                  | (0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                                 | (0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))) 
                                                << 1U));
    vlTOPp->single_cycle_cpu__DOT__rs2_dout = ((0U 
                                                != 
                                                (0x1fU 
                                                 & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                    >> 0x14U)))
                                                ? vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data
                                               [(0x1fU 
                                                 & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                    >> 0x14U))]
                                                : 0U);
    vlTOPp->single_cycle_cpu__DOT__notsigned = ((((
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                   & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                      >> 0xeU)) 
                                                  | ((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                     & (3U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                            >> 0xcU))))) 
                                                 | ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                    & (3U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                           >> 0xcU))))) 
                                                | ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                   & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                      >> 0xdU)));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x3eU 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                & (0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                       >> 0xcU)))));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x3dU 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | (((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 & (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU)))) 
                                                << 1U));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x3bU 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | (((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 & (4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU)))) 
                                                << 2U));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x37U 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | (((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 & (5U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU)))) 
                                                << 3U));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x2fU 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | (((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 & (6U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU)))) 
                                                << 4U));
    vlTOPp->single_cycle_cpu__DOT__branch = ((0x1fU 
                                              & (IData)(vlTOPp->single_cycle_cpu__DOT__branch)) 
                                             | (((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)) 
                                                 & (7U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0xcU)))) 
                                                << 5U));
    vlTOPp->single_cycle_cpu__DOT__alu_op = ((2U & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_op)) 
                                             | (0U 
                                                != (IData)(vlTOPp->single_cycle_cpu__DOT__branch)));
    vlTOPp->single_cycle_cpu__DOT__imm12 = (0xfffU 
                                            & ((0U 
                                                != (IData)(vlTOPp->single_cycle_cpu__DOT__branch))
                                                ? (
                                                   (0x800U 
                                                    & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                       >> 0x14U)) 
                                                   | ((0x400U 
                                                       & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                          << 3U)) 
                                                      | ((0x3f0U 
                                                          & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                             >> 0x15U)) 
                                                         | (0xfU 
                                                            & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                               >> 8U)))))
                                                : (
                                                   (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))
                                                    ? 
                                                   ((0xfe0U 
                                                     & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                          >> 7U)))
                                                    : 
                                                   (vlTOPp->single_cycle_cpu__DOT__inst 
                                                    >> 0x14U))));
    vlTOPp->single_cycle_cpu__DOT__alu_control = ((2U 
                                                   & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_op))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst)
                                                      ? 0U
                                                      : 1U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst)
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                           >> 0x19U)))
                                                       ? 9U
                                                       : 0xbU)
                                                      : 3U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst)
                                                      ? 0xeU
                                                      : 6U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst)
                                                      ? 7U
                                                      : 
                                                     (((vlTOPp->single_cycle_cpu__DOT__inst 
                                                        >> 0x1eU) 
                                                       & (0x33U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->single_cycle_cpu__DOT__inst)))
                                                       ? 6U
                                                       : 2U))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_op))
                                                    ? 
                                                   ((IData)(vlTOPp->single_cycle_cpu__DOT__notsigned)
                                                     ? 0xeU
                                                     : 6U)
                                                    : 2U));
    vlTOPp->single_cycle_cpu__DOT__imm32 = ((0xfffff000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->single_cycle_cpu__DOT__imm12) 
                                                               >> 0xbU)))) 
                                                << 0xcU)) 
                                            | (IData)(vlTOPp->single_cycle_cpu__DOT__imm12));
    vlTOPp->single_cycle_cpu__DOT__alu_in2 = ((3U == (IData)(vlTOPp->single_cycle_cpu__DOT__alu_src))
                                               ? vlTOPp->single_cycle_cpu__DOT__imm32
                                               : ((1U 
                                                   == (IData)(vlTOPp->single_cycle_cpu__DOT__alu_src))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->single_cycle_cpu__DOT__inst)
                                                   : vlTOPp->single_cycle_cpu__DOT__rs2_dout));
    vlTOPp->single_cycle_cpu__DOT__alu_result = ((8U 
                                                  & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     + vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                     : 
                                                    ((vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                      < vlTOPp->single_cycle_cpu__DOT__alu_in2) 
                                                     << 0x1fU))
                                                    : 
                                                   (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                    + vlTOPp->single_cycle_cpu__DOT__alu_in2))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,32, vlTOPp->single_cycle_cpu__DOT__alu_in1, vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      : 
                                                     (- 
                                                      (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                       >> 0x1fU)))
                                                     : 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     + vlTOPp->single_cycle_cpu__DOT__alu_in2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      ? 
                                                     (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                      >> vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     + vlTOPp->single_cycle_cpu__DOT__alu_in2))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      ? 
                                                     (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                      << vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     - vlTOPp->single_cycle_cpu__DOT__alu_in2))
                                                    : 
                                                   (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                    + vlTOPp->single_cycle_cpu__DOT__alu_in2))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     ^ vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                     : 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     + vlTOPp->single_cycle_cpu__DOT__alu_in2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->single_cycle_cpu__DOT__alu_control))
                                                     ? 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     | vlTOPp->single_cycle_cpu__DOT__alu_in2)
                                                     : 
                                                    (vlTOPp->single_cycle_cpu__DOT__alu_in1 
                                                     & vlTOPp->single_cycle_cpu__DOT__alu_in2)))));
    vlTOPp->single_cycle_cpu__DOT__dmem_dout = ((0U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                     >> 0xcU)))
                                                 ? 
                                                ((IData)(vlTOPp->single_cycle_cpu__DOT__notsigned)
                                                  ? 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst))
                                                   ? 
                                                  (0xffU 
                                                   & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                   [
                                                   (0x3ffU 
                                                    & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                       >> 2U))])
                                                   : 0U)
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                                      [
                                                                      (0x3ffU 
                                                                       & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                                          >> 2U))] 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                      [
                                                      (0x3ffU 
                                                       & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                          >> 2U))]))
                                                   : 0U))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (3U 
                                                   & (vlTOPp->single_cycle_cpu__DOT__inst 
                                                      >> 0xcU)))
                                                  ? 
                                                 ((IData)(vlTOPp->single_cycle_cpu__DOT__notsigned)
                                                   ? 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                    [
                                                    (0x3ffU 
                                                     & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                        >> 2U))])
                                                    : 0U)
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                                       [
                                                                       (0x3ffU 
                                                                        & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                                           >> 2U))] 
                                                                       >> 0xfU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                       [
                                                       (0x3ffU 
                                                        & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                           >> 2U))]))
                                                    : 0U))
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->single_cycle_cpu__DOT__inst))
                                                   ? 
                                                  vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                                                  [
                                                  (0x3ffU 
                                                   & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                      >> 2U))]
                                                   : 0U)));
    vlTOPp->single_cycle_cpu__DOT__pc_next_sel = ((1U 
                                                   & (((((((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                           & (~ (IData)(
                                                                        (0U 
                                                                         != vlTOPp->single_cycle_cpu__DOT__alu_result)))) 
                                                          | (((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                              >> 1U) 
                                                             & (0U 
                                                                != vlTOPp->single_cycle_cpu__DOT__alu_result))) 
                                                         | (((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                             >> 2U) 
                                                            & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                               >> 0x1fU))) 
                                                        | (((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                            >> 3U) 
                                                           & (~ 
                                                              (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                               >> 0x1fU)))) 
                                                       | (((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                           >> 4U) 
                                                          & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                             >> 0x1fU))) 
                                                      | (((IData)(vlTOPp->single_cycle_cpu__DOT__branch) 
                                                          >> 5U) 
                                                         & (~ 
                                                            (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                                             >> 0x1fU)))))
                                                   ? 3U
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->single_cycle_cpu__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->single_cycle_cpu__DOT__inst))
                                                     ? 1U
                                                     : 0U)));
    vlTOPp->single_cycle_cpu__DOT__pc_next = ((3U == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                               ? (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                                  + 
                                                  (0xfffffffeU 
                                                   & (vlTOPp->single_cycle_cpu__DOT__imm32 
                                                      << 1U)))
                                               : ((2U 
                                                   == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                                   ? 
                                                  (vlTOPp->single_cycle_cpu__DOT__pc_curr 
                                                   + 
                                                   ((0xfff00000U 
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
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->single_cycle_cpu__DOT__pc_next_sel))
                                                    ? vlTOPp->single_cycle_cpu__DOT__alu_result
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlTOPp->single_cycle_cpu__DOT__pc_curr))));
}

void Vsingle_cycle_cpu::_eval_initial(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_eval_initial\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_b = vlTOPp->reset_b;
}

void Vsingle_cycle_cpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::final\n"); );
    // Variables
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsingle_cycle_cpu::_eval_settle(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_eval_settle\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vsingle_cycle_cpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_b = VL_RAND_RESET_I(1);
    single_cycle_cpu__DOT__inst = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__rs2_dout = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__alu_in1 = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__alu_in2 = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__alu_control = VL_RAND_RESET_I(4);
    single_cycle_cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__dmem_dout = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__branch = VL_RAND_RESET_I(6);
    single_cycle_cpu__DOT__alu_src = VL_RAND_RESET_I(2);
    single_cycle_cpu__DOT__alu_op = VL_RAND_RESET_I(2);
    single_cycle_cpu__DOT__notsigned = VL_RAND_RESET_I(1);
    single_cycle_cpu__DOT__isCompare = VL_RAND_RESET_I(1);
    single_cycle_cpu__DOT__imm32 = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__imm12 = VL_RAND_RESET_I(12);
    single_cycle_cpu__DOT__pc_curr = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__pc_next = VL_RAND_RESET_I(32);
    single_cycle_cpu__DOT__pc_next_sel = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            single_cycle_cpu__DOT__u_imem_0__DOT__data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    single_cycle_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            single_cycle_cpu__DOT__u_dmem_0__DOT__data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
