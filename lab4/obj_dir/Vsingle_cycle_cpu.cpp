// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsingle_cycle_cpu.h for the primary calling header

#include "Vsingle_cycle_cpu.h"
#include "Vsingle_cycle_cpu__Syms.h"

//==========

void Vsingle_cycle_cpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsingle_cycle_cpu::eval\n"); );
    Vsingle_cycle_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("single_cycle_cpu.sv", 15, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsingle_cycle_cpu::_eval_initial_loop(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("single_cycle_cpu.sv", 15, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vsingle_cycle_cpu::_sequent__TOP__3(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_sequent__TOP__3\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    CData/*0:0*/ __Vdlyvset__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    CData/*4:0*/ __Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*7:0*/ __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*4:0*/ __Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2;
    SData/*9:0*/ __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0;
    SData/*9:0*/ __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1;
    SData/*15:0*/ __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1;
    SData/*9:0*/ __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2;
    IData/*31:0*/ __Vdlyvval__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    IData/*31:0*/ __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2;
    // Body
    __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0 = 0U;
    __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1 = 0U;
    __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2 = 0U;
    __Vdlyvset__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0 = 0U;
    if ((0x23U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) {
        if ((0U == (3U & (vlTOPp->single_cycle_cpu__DOT__inst 
                          >> 0xcU)))) {
            __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0 
                = (0xffU & vlTOPp->single_cycle_cpu__DOT__rs2_dout);
            __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0 = 1U;
            __Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0 = 0U;
            __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0 
                = (0x3ffU & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                             >> 2U));
        } else {
            if ((1U == (3U & (vlTOPp->single_cycle_cpu__DOT__inst 
                              >> 0xcU)))) {
                __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1 
                    = (0xffffU & vlTOPp->single_cycle_cpu__DOT__rs2_dout);
                __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1 = 1U;
                __Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1 = 0U;
                __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1 
                    = (0x3ffU & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                 >> 2U));
            } else {
                __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2 
                    = vlTOPp->single_cycle_cpu__DOT__rs2_dout;
                __Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2 = 1U;
                __Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2 
                    = (0x3ffU & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                                 >> 2U));
            }
        }
    }
    if (((((((((0x33U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)) 
               | (0x13U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
              | (3U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
             | (0x17U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
            | (0x37U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
           | (IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)) 
          | (0x6fU == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst))) 
         | (0x67U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)))) {
        __Vdlyvval__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0 
            = (((0x6fU == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)) 
                | (0x67U == (0x7fU & vlTOPp->single_cycle_cpu__DOT__inst)))
                ? ((IData)(4U) + vlTOPp->single_cycle_cpu__DOT__pc_curr)
                : ((IData)(vlTOPp->single_cycle_cpu__DOT__isCompare)
                    ? (1U & (vlTOPp->single_cycle_cpu__DOT__alu_result 
                             >> 0x1fU)) : ((0x37U == 
                                            (0x7fU 
                                             & vlTOPp->single_cycle_cpu__DOT__inst))
                                            ? (0xfffff000U 
                                               & vlTOPp->single_cycle_cpu__DOT__inst)
                                            : ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->single_cycle_cpu__DOT__inst))
                                                ? vlTOPp->single_cycle_cpu__DOT__dmem_dout
                                                : vlTOPp->single_cycle_cpu__DOT__alu_result))));
        __Vdlyvset__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0 = 1U;
        __Vdlyvdim0__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0 
            = (0x1fU & (vlTOPp->single_cycle_cpu__DOT__inst 
                        >> 7U));
    }
    if (__Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0) {
        vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0))) 
                & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                [__Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0]) 
               | ((IData)(__Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0) 
                  << (IData)(__Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v0)));
    }
    if (__Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1) {
        vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1))) 
                & vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data
                [__Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1]) 
               | ((IData)(__Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1) 
                  << (IData)(__Vdlyvlsb__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v1)));
    }
    if (__Vdlyvset__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2) {
        vlTOPp->single_cycle_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2] 
            = __Vdlyvval__single_cycle_cpu__DOT__u_dmem_0__DOT__data__v2;
    }
    if (__Vdlyvset__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0) {
        vlTOPp->single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data[__Vdlyvdim0__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0] 
            = __Vdlyvval__single_cycle_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    }
}

VL_INLINE_OPT void Vsingle_cycle_cpu::_sequent__TOP__5(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_sequent__TOP__5\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->single_cycle_cpu__DOT__pc_curr = ((IData)(vlTOPp->reset_b)
                                               ? vlTOPp->single_cycle_cpu__DOT__pc_next
                                               : 0U);
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

void Vsingle_cycle_cpu::_eval(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_eval\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_b)) & (IData)(vlTOPp->__Vclklast__TOP__reset_b)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_b = vlTOPp->reset_b;
}

VL_INLINE_OPT QData Vsingle_cycle_cpu::_change_request(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_change_request\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vsingle_cycle_cpu::_change_request_1(Vsingle_cycle_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_change_request_1\n"); );
    Vsingle_cycle_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsingle_cycle_cpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingle_cycle_cpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_b & 0xfeU))) {
        Verilated::overWidthError("reset_b");}
}
#endif  // VL_DEBUG
