// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline_cpu.h for the primary calling header

#include "Vpipeline_cpu.h"
#include "Vpipeline_cpu__Syms.h"

//==========

void Vpipeline_cpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpipeline_cpu::eval\n"); );
    Vpipeline_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("pipeline_cpu.sv", 99, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vpipeline_cpu::_eval_initial_loop(Vpipeline_cpu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("pipeline_cpu.sv", 99, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vpipeline_cpu::_sequent__TOP__2(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_sequent__TOP__2\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[0U] = vlTOPp->pipeline_cpu__DOT__ex[0U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] = vlTOPp->pipeline_cpu__DOT__ex[1U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U] = vlTOPp->pipeline_cpu__DOT__ex[2U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] = vlTOPp->pipeline_cpu__DOT__ex[3U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] = vlTOPp->pipeline_cpu__DOT__ex[4U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U] = vlTOPp->pipeline_cpu__DOT__ex[5U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U] = vlTOPp->pipeline_cpu__DOT__ex[6U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U] = vlTOPp->pipeline_cpu__DOT__ex[7U];
    vlTOPp->__Vdly__pipeline_cpu__DOT__ex[8U] = vlTOPp->pipeline_cpu__DOT__ex[8U];
    if (vlTOPp->reset_b) {
        if (((IData)(vlTOPp->pipeline_cpu__DOT__id_flush) 
             | (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use))) {
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[0U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U] = 0U;
            vlTOPp->__Vdly__pipeline_cpu__DOT__ex[8U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use)))) {
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U] 
                    = ((0xfffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U]) 
                       | (0xfff00000U & (vlTOPp->pipeline_cpu__DOT__id[2U] 
                                         << 0x14U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[8U] 
                    = (0xfffffU & (vlTOPp->pipeline_cpu__DOT__id[2U] 
                                   >> 0xcU));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U] 
                    = ((0xfffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U]) 
                       | (0xfff00000U & ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                            >> 5U) 
                                           & ((0x1fU 
                                               & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                   << 0x11U) 
                                                  | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                     >> 0xfU))) 
                                              == (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U)))))
                                           ? vlTOPp->pipeline_cpu__DOT__rd_din
                                           : ((0U != 
                                               (0x1fU 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0xfU))))
                                               ? vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data
                                              [(0x1fU 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0xfU)))]
                                               : 0U)) 
                                         << 0x14U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U] 
                    = ((0xfff00000U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U]) 
                       | (0xfffffU & ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                         >> 5U) & (
                                                   (0x1fU 
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
                                           [(0x1fU 
                                             & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0x11U) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0xfU)))]
                                            : 0U)) 
                                      >> 0xcU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U] 
                    = ((0xfffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U]) 
                       | (0xfff00000U & ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                            >> 5U) 
                                           & ((0x1fU 
                                               & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                   << 0xcU) 
                                                  | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                     >> 0x14U))) 
                                              == (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U)))))
                                           ? vlTOPp->pipeline_cpu__DOT__rd_din
                                           : ((0U != 
                                               (0x1fU 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0x14U))))
                                               ? vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data
                                              [(0x1fU 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0x14U)))]
                                               : 0U)) 
                                         << 0x14U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U] 
                    = ((0xfff00000U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U]) 
                       | (0xfffffU & ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                         >> 5U) & (
                                                   (0x1fU 
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
                                           [(0x1fU 
                                             & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                 << 0xcU) 
                                                | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                   >> 0x14U)))]
                                            : 0U)) 
                                      >> 0xcU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] 
                    = ((0xfffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U]) 
                       | (0xfff00000U & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                         << 0x14U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U] 
                    = ((0xfff00000U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U]) 
                       | (0xfffffU & ((0xfffffU & (- (IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                                                 >> 0xbU))))) 
                                      | ((IData)(vlTOPp->pipeline_cpu__DOT__imm12) 
                                         >> 0xcU))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] 
                    = ((0xfff01fffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U]) 
                       | (0xfe000U & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                      << 0xdU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] 
                    = ((0xffffe3ffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U]) 
                       | (0x1c00U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                      << 0x1eU) | (0x3ffffc00U 
                                                   & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 2U)))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] 
                    = ((0xfffffc07U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U]) 
                       | (0x3f8U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                     << 0xaU) | (0x3f8U 
                                                 & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                    >> 0x16U)))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0x7fffffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0x80000000U & ((IData)(vlTOPp->pipeline_cpu__DOT__branch) 
                                         << 0x1fU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] 
                    = ((0xfffffff8U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U]) 
                       | (0x7fffffffU & ((IData)(vlTOPp->pipeline_cpu__DOT__branch) 
                                         >> 1U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0x9fffffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xe0000000U & ((((((3U == 
                                              (0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             | (0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                            | (0x13U 
                                               == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                           | (0x67U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])))
                                           ? 3U : (
                                                   ((0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                                    | (0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->pipeline_cpu__DOT__id[1U])))
                                                    ? 1U
                                                    : 0U)) 
                                         << 0x1dU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xe7ffffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xf8000000U & ((IData)(vlTOPp->pipeline_cpu__DOT__alu_op) 
                                         << 0x1bU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfbffffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xfc000000U & ((3U == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 0x1aU)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfdffffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xfe000000U & ((0x23U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 0x19U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfe0fffffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0x1f00000U & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                        << 5U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfff07fffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xf8000U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                       << 0x1bU) | 
                                      (0x7ff8000U & 
                                       (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                        >> 5U)))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xffff83ffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0x7c00U & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                     << 3U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfffffdffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xfffffe00U & (((((((((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                                | (0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                               | (3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                              | (0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                             | (0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                            | (IData)(vlTOPp->pipeline_cpu__DOT__isCompare)) 
                                           | (0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                          | (0x67U 
                                             == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                         << 9U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xfffffeffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xffffff00U & ((3U == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 8U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U] 
                    = ((0xffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U]) 
                       | (0xfff00000U & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                         << 8U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] 
                    = ((0xffffff00U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U]) 
                       | (0xffU & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                   >> 0x18U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xffU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xffffff00U & (vlTOPp->pipeline_cpu__DOT__imm32_J 
                                         << 8U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U] 
                    = ((0xffffff00U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U]) 
                       | (0xffU & (vlTOPp->pipeline_cpu__DOT__imm32_J 
                                   >> 0x18U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xffffff7fU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xffffff80U & ((0x37U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 7U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xffffffbfU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xffffffc0U & ((0x17U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 6U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xffffffdfU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xffffffe0U & ((IData)(vlTOPp->pipeline_cpu__DOT__isCompare) 
                                         << 5U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xffffffefU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xfffffff0U & ((0x6fU == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 4U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xfffffff7U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (0xfffffff8U & ((0x67U == 
                                          (0x7fU & 
                                           vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                         << 3U)));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xfffffff9U & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (6U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                 << 0x15U) | (0x1ffffeU 
                                              & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                 >> 0xbU)))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] 
                    = ((0xfffffffeU & vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U]) 
                       | (((((3U == (0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                             & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                >> 0xeU)) | ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             & (3U 
                                                == 
                                                (7U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x14U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xcU)))))) 
                           | ((0x13U == (0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                              & (3U == (7U & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                               << 0x14U) 
                                              | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                 >> 0xcU)))))) 
                          | ((0x63U == (0x7fU & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                             & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                >> 0xdU))));
                vlTOPp->__Vdly__pipeline_cpu__DOT__ex[0U] 
                    = vlTOPp->pipeline_cpu__DOT__id[0U];
            }
        }
    } else {
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[0U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U] = 0U;
        vlTOPp->__Vdly__pipeline_cpu__DOT__ex[8U] = 0U;
    }
    if (vlTOPp->reset_b) {
        if (vlTOPp->pipeline_cpu__DOT__if_flush) {
            vlTOPp->pipeline_cpu__DOT__id[0U] = 0U;
            vlTOPp->pipeline_cpu__DOT__id[1U] = 0U;
            vlTOPp->pipeline_cpu__DOT__id[2U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use)))) {
                vlTOPp->pipeline_cpu__DOT__id[2U] = vlTOPp->pipeline_cpu__DOT__pc_curr;
                vlTOPp->pipeline_cpu__DOT__id[1U] = 
                    vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__data
                    [(0x3ffU & (vlTOPp->pipeline_cpu__DOT__pc_curr 
                                >> 2U))];
                vlTOPp->pipeline_cpu__DOT__id[0U] = 
                    ((IData)(4U) + vlTOPp->pipeline_cpu__DOT__pc_curr);
            }
        }
    } else {
        vlTOPp->pipeline_cpu__DOT__id[0U] = 0U;
        vlTOPp->pipeline_cpu__DOT__id[1U] = 0U;
        vlTOPp->pipeline_cpu__DOT__id[2U] = 0U;
    }
    if (vlTOPp->reset_b) {
        if ((1U & (~ (IData)(vlTOPp->pipeline_cpu__DOT__stall_by_load_use)))) {
            vlTOPp->pipeline_cpu__DOT__pc_curr = vlTOPp->pipeline_cpu__DOT__pc_next;
        }
    } else {
        vlTOPp->pipeline_cpu__DOT__pc_curr = 0U;
    }
    vlTOPp->pipeline_cpu__DOT__isCompare = (((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             | (0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                            & ((2U 
                                                == 
                                                (7U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x14U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xcU)))) 
                                               | (3U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                         >> 0xcU))))));
    vlTOPp->pipeline_cpu__DOT__imm32_J = ((0xfff00000U 
                                           & ((- (IData)(
                                                         (1U 
                                                          & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                             >> 0x1fU)))) 
                                              << 0x14U)) 
                                          | ((0xff000U 
                                              & vlTOPp->pipeline_cpu__DOT__id[1U]) 
                                             | ((0x800U 
                                                 & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                       << 0xcU) 
                                                      | (0xffeU 
                                                         & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                            >> 0x14U)))))));
    vlTOPp->pipeline_cpu__DOT__alu_op = ((1U & (IData)(vlTOPp->pipeline_cpu__DOT__alu_op)) 
                                         | ((((0x33U 
                                               == (0x7fU 
                                                   & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                              | (0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                            << 1U));
    vlTOPp->pipeline_cpu__DOT__branch = ((0xeU & (IData)(vlTOPp->pipeline_cpu__DOT__branch)) 
                                         | ((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                            & (0U == 
                                               (7U 
                                                & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                    << 0x14U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                      >> 0xcU))))));
    vlTOPp->pipeline_cpu__DOT__branch = ((0xdU & (IData)(vlTOPp->pipeline_cpu__DOT__branch)) 
                                         | (((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             & (1U 
                                                == 
                                                (7U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x14U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xcU))))) 
                                            << 1U));
    vlTOPp->pipeline_cpu__DOT__branch = ((0xbU & (IData)(vlTOPp->pipeline_cpu__DOT__branch)) 
                                         | (((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             & (4U 
                                                == 
                                                (7U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x14U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xcU))))) 
                                            << 2U));
    vlTOPp->pipeline_cpu__DOT__branch = ((7U & (IData)(vlTOPp->pipeline_cpu__DOT__branch)) 
                                         | (((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->pipeline_cpu__DOT__id[1U])) 
                                             & (5U 
                                                == 
                                                (7U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0x14U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0xcU))))) 
                                            << 3U));
    vlTOPp->pipeline_cpu__DOT__imm12 = (0xfffU & ((0U 
                                                   != (IData)(vlTOPp->pipeline_cpu__DOT__branch))
                                                   ? 
                                                  ((0x800U 
                                                    & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0x14U)) 
                                                   | ((0x400U 
                                                       & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                          << 3U)) 
                                                      | ((0x3f0U 
                                                          & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                              << 0xbU) 
                                                             | (0x7f0U 
                                                                & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                                   >> 0x15U)))) 
                                                         | (0xfU 
                                                            & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                                << 0x18U) 
                                                               | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                                  >> 8U))))))
                                                   : 
                                                  ((0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->pipeline_cpu__DOT__id[1U]))
                                                    ? 
                                                   ((0xfe0U 
                                                     & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                         << 0xcU) 
                                                        | (0xfe0U 
                                                           & (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                              >> 0x14U)))) 
                                                    | (0x1fU 
                                                       & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                           << 0x19U) 
                                                          | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                             >> 7U))))
                                                    : 
                                                   ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                                       >> 0x14U)))));
    vlTOPp->pipeline_cpu__DOT__alu_op = ((2U & (IData)(vlTOPp->pipeline_cpu__DOT__alu_op)) 
                                         | (0U != (IData)(vlTOPp->pipeline_cpu__DOT__branch)));
}

VL_INLINE_OPT void Vpipeline_cpu::_sequent__TOP__3(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_sequent__TOP__3\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    CData/*0:0*/ __Vdlyvset__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    CData/*4:0*/ __Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*7:0*/ __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0;
    CData/*4:0*/ __Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2;
    SData/*9:0*/ __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0;
    SData/*9:0*/ __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1;
    SData/*15:0*/ __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1;
    SData/*9:0*/ __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2;
    IData/*31:0*/ __Vdlyvval__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    IData/*31:0*/ __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2;
    // Body
    __Vdlyvset__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0 = 0U;
    __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0 = 0U;
    __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1 = 0U;
    __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2 = 0U;
    if ((0x20U & vlTOPp->pipeline_cpu__DOT__wb[3U])) {
        __Vdlyvval__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0 
            = vlTOPp->pipeline_cpu__DOT__rd_din;
        __Vdlyvset__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0 = 1U;
        __Vdlyvdim0__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0 
            = (0x1fU & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                         << 0x1aU) | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                      >> 6U)));
    }
    if ((0x4000U & vlTOPp->pipeline_cpu__DOT__mem[3U])) {
        if ((0U == (3U & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                           << 0x1cU) | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                        >> 4U))))) {
            __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0 
                = (0xffU & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                             << 0x10U) | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                          >> 0x10U)));
            __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0 = 1U;
            __Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0 = 0U;
            __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0 
                = (0x3ffU & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                              << 0xeU) | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                          >> 0x12U)));
        } else {
            if ((1U == (3U & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                               << 0x1cU) | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                            >> 4U))))) {
                __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1 
                    = (0xffffU & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                   << 0x10U) | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                >> 0x10U)));
                __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1 = 1U;
                __Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1 = 0U;
                __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1 
                    = (0x3ffU & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                  << 0xeU) | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                              >> 0x12U)));
            } else {
                __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2 
                    = ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                        << 0x10U) | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                     >> 0x10U));
                __Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2 = 1U;
                __Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2 
                    = (0x3ffU & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                  << 0xeU) | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                              >> 0x12U)));
            }
        }
    }
    if (__Vdlyvset__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0) {
        vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[__Vdlyvdim0__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0] 
            = __Vdlyvval__pipeline_cpu__DOT__u_regfile_0__DOT__rf_data__v0;
    }
    if (__Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0) {
        vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0))) 
                & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                [__Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0]) 
               | ((IData)(__Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0) 
                  << (IData)(__Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v0)));
    }
    if (__Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1) {
        vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1))) 
                & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                [__Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1]) 
               | ((IData)(__Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1) 
                  << (IData)(__Vdlyvlsb__pipeline_cpu__DOT__u_dmem_0__DOT__data__v1)));
    }
    if (__Vdlyvset__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2) {
        vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data[__Vdlyvdim0__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2] 
            = __Vdlyvval__pipeline_cpu__DOT__u_dmem_0__DOT__data__v2;
    }
}

VL_INLINE_OPT void Vpipeline_cpu::_sequent__TOP__5(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_sequent__TOP__5\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_b) {
        vlTOPp->pipeline_cpu__DOT__wb[4U] = ((0x7ffU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[4U]) 
                                             | (0xfffff800U 
                                                & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                    << 0x1bU) 
                                                   | (0x7fff800U 
                                                      & (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                         >> 5U)))));
        vlTOPp->pipeline_cpu__DOT__wb[5U] = (0x7ffU 
                                             & (vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                >> 5U));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0x7ffU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (0xfffff800U 
                                                & (vlTOPp->pipeline_cpu__DOT__dmem_dout 
                                                   << 0xbU)));
        vlTOPp->pipeline_cpu__DOT__wb[4U] = ((0xfffff800U 
                                              & vlTOPp->pipeline_cpu__DOT__wb[4U]) 
                                             | (0x7ffU 
                                                & (vlTOPp->pipeline_cpu__DOT__dmem_dout 
                                                   >> 0x15U)));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xfffff83fU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (0x7c0U 
                                                & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                    << 0x1dU) 
                                                   | (0x1fffffc0U 
                                                      & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                         >> 3U)))));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xffffffdfU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (0x20U 
                                                & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                   >> 3U)));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xffffffefU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (0x10U 
                                                & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                   >> 3U)));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xfffffff7U 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (8U 
                                                & (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                   << 1U)));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xfffffffbU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (4U 
                                                & (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                   >> 1U)));
        vlTOPp->pipeline_cpu__DOT__wb[2U] = ((3U & 
                                              vlTOPp->pipeline_cpu__DOT__wb[2U]) 
                                             | (0xfffffffcU 
                                                & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                    << 0x1bU) 
                                                   | (0x7fffffcU 
                                                      & (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                         >> 5U)))));
        vlTOPp->pipeline_cpu__DOT__wb[3U] = ((0xfffffffcU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[3U]) 
                                             | (3U 
                                                & (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                   >> 5U)));
        vlTOPp->pipeline_cpu__DOT__wb[2U] = ((0xfffffffdU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[2U]) 
                                             | (2U 
                                                & vlTOPp->pipeline_cpu__DOT__mem[2U]));
        vlTOPp->pipeline_cpu__DOT__wb[1U] = ((0xfffffffeU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[1U]) 
                                             | (1U 
                                                & vlTOPp->pipeline_cpu__DOT__mem[1U]));
        vlTOPp->pipeline_cpu__DOT__wb[0U] = vlTOPp->pipeline_cpu__DOT__mem[0U];
        vlTOPp->pipeline_cpu__DOT__wb[1U] = ((1U & 
                                              vlTOPp->pipeline_cpu__DOT__wb[1U]) 
                                             | (0xfffffffeU 
                                                & vlTOPp->pipeline_cpu__DOT__mem[1U]));
        vlTOPp->pipeline_cpu__DOT__wb[2U] = ((0xfffffffeU 
                                              & vlTOPp->pipeline_cpu__DOT__wb[2U]) 
                                             | (1U 
                                                & vlTOPp->pipeline_cpu__DOT__mem[2U]));
    } else {
        vlTOPp->pipeline_cpu__DOT__wb[0U] = 0U;
        vlTOPp->pipeline_cpu__DOT__wb[1U] = 0U;
        vlTOPp->pipeline_cpu__DOT__wb[2U] = 0U;
        vlTOPp->pipeline_cpu__DOT__wb[3U] = 0U;
        vlTOPp->pipeline_cpu__DOT__wb[4U] = 0U;
        vlTOPp->pipeline_cpu__DOT__wb[5U] = 0U;
    }
    vlTOPp->pipeline_cpu__DOT__rd_din = ((1U & ((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                 >> 3U) 
                                                | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                   >> 2U)))
                                          ? ((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                              << 0x1eU) 
                                             | (vlTOPp->pipeline_cpu__DOT__wb[2U] 
                                                >> 2U))
                                          : ((2U & 
                                              vlTOPp->pipeline_cpu__DOT__wb[2U])
                                              ? ((vlTOPp->pipeline_cpu__DOT__wb[2U] 
                                                  << 0x1fU) 
                                                 | (vlTOPp->pipeline_cpu__DOT__wb[1U] 
                                                    >> 1U))
                                              : ((1U 
                                                  & vlTOPp->pipeline_cpu__DOT__wb[1U])
                                                  ? 
                                                 vlTOPp->pipeline_cpu__DOT__wb[0U]
                                                  : 
                                                 ((0x10U 
                                                   & vlTOPp->pipeline_cpu__DOT__wb[3U])
                                                   ? 
                                                  ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                    << 0x15U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                      >> 0xbU))
                                                   : 
                                                  ((vlTOPp->pipeline_cpu__DOT__wb[5U] 
                                                    << 0x15U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      >> 0xbU))))));
    if (vlTOPp->reset_b) {
        vlTOPp->pipeline_cpu__DOT__mem[4U] = ((0xffffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[4U]) 
                                              | (0xffff0000U 
                                                 & (vlTOPp->pipeline_cpu__DOT__alu_result 
                                                    << 0x10U)));
        vlTOPp->pipeline_cpu__DOT__mem[5U] = (0xffffU 
                                              & (vlTOPp->pipeline_cpu__DOT__alu_result 
                                                 >> 0x10U));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0xffff0000U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                     << 0x1cU) 
                                                    | (0xfff0000U 
                                                       & (vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                          >> 4U)))));
        vlTOPp->pipeline_cpu__DOT__mem[4U] = ((0xffff0000U 
                                               & vlTOPp->pipeline_cpu__DOT__mem[4U]) 
                                              | (0xffffU 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                    >> 4U)));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffff7fffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x8000U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                    >> 0xbU)));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffffbfffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x4000U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                    >> 0xbU)));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffffc1ffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x3e00U 
                                                 & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     << 0x1fU) 
                                                    | (0x7ffffe00U 
                                                       & (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                          >> 1U)))));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xfffffeffU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x100U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                    >> 1U)));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffffff7fU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x80U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                    >> 1U)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0x7fU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (0xffffff80U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[0U] 
                                                    << 7U)));
        vlTOPp->pipeline_cpu__DOT__mem[3U] = ((0xffffff80U 
                                               & vlTOPp->pipeline_cpu__DOT__mem[3U]) 
                                              | (0x7fU 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[0U] 
                                                    >> 0x19U)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0xffffffbfU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (0x40U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    << 6U)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0xffffffcfU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (0x30U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    << 3U)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0xfffffff7U 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (8U 
                                                 & vlTOPp->pipeline_cpu__DOT__ex[1U]));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0xfffffffbU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (4U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    >> 2U)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = ((0xfffffffdU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[2U]) 
                                              | (2U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    >> 4U)));
        vlTOPp->pipeline_cpu__DOT__mem[1U] = ((1U & 
                                               vlTOPp->pipeline_cpu__DOT__mem[1U]) 
                                              | (2U 
                                                 & (vlTOPp->pipeline_cpu__DOT__alu_result 
                                                    >> 0x1eU)));
        vlTOPp->pipeline_cpu__DOT__mem[2U] = (0xfffffffeU 
                                              & vlTOPp->pipeline_cpu__DOT__mem[2U]);
        vlTOPp->pipeline_cpu__DOT__mem[1U] = ((0xfffffffeU 
                                               & vlTOPp->pipeline_cpu__DOT__mem[1U]) 
                                              | (1U 
                                                 & (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    >> 7U)));
        vlTOPp->pipeline_cpu__DOT__mem[0U] = ((vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                               << 0x18U) 
                                              | (vlTOPp->pipeline_cpu__DOT__ex[2U] 
                                                 >> 8U));
    } else {
        vlTOPp->pipeline_cpu__DOT__mem[0U] = 0U;
        vlTOPp->pipeline_cpu__DOT__mem[1U] = 0U;
        vlTOPp->pipeline_cpu__DOT__mem[2U] = 0U;
        vlTOPp->pipeline_cpu__DOT__mem[3U] = 0U;
        vlTOPp->pipeline_cpu__DOT__mem[4U] = 0U;
        vlTOPp->pipeline_cpu__DOT__mem[5U] = 0U;
    }
    vlTOPp->pipeline_cpu__DOT__ex[0U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[0U];
    vlTOPp->pipeline_cpu__DOT__ex[1U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[1U];
    vlTOPp->pipeline_cpu__DOT__ex[2U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[2U];
    vlTOPp->pipeline_cpu__DOT__ex[3U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[3U];
    vlTOPp->pipeline_cpu__DOT__ex[4U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[4U];
    vlTOPp->pipeline_cpu__DOT__ex[5U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[5U];
    vlTOPp->pipeline_cpu__DOT__ex[6U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[6U];
    vlTOPp->pipeline_cpu__DOT__ex[7U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[7U];
    vlTOPp->pipeline_cpu__DOT__ex[8U] = vlTOPp->__Vdly__pipeline_cpu__DOT__ex[8U];
    vlTOPp->pipeline_cpu__DOT__dmem_dout = ((0U == 
                                             (3U & 
                                              ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                << 0x1cU) 
                                               | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                  >> 4U))))
                                             ? ((0x40U 
                                                 & vlTOPp->pipeline_cpu__DOT__mem[2U])
                                                 ? 
                                                ((0x8000U 
                                                  & vlTOPp->pipeline_cpu__DOT__mem[3U])
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                  [
                                                  (0x3ffU 
                                                   & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                       << 0xeU) 
                                                      | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                         >> 0x12U)))])
                                                  : 0U)
                                                 : 
                                                ((0x8000U 
                                                  & vlTOPp->pipeline_cpu__DOT__mem[3U])
                                                  ? 
                                                 ((0xffffff00U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                                     [
                                                                     (0x3ffU 
                                                                      & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                                          << 0xeU) 
                                                                         | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                                            >> 0x12U)))] 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (0xffU 
                                                     & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                     [
                                                     (0x3ffU 
                                                      & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                          << 0xeU) 
                                                         | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                            >> 0x12U)))]))
                                                  : 0U))
                                             : ((1U 
                                                 == 
                                                 (3U 
                                                  & ((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                      << 0x1cU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__mem[2U] 
                                                        >> 4U))))
                                                 ? 
                                                ((0x40U 
                                                  & vlTOPp->pipeline_cpu__DOT__mem[2U])
                                                  ? 
                                                 ((0x8000U 
                                                   & vlTOPp->pipeline_cpu__DOT__mem[3U])
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                   [
                                                   (0x3ffU 
                                                    & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                        << 0xeU) 
                                                       | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                          >> 0x12U)))])
                                                   : 0U)
                                                  : 
                                                 ((0x8000U 
                                                   & vlTOPp->pipeline_cpu__DOT__mem[3U])
                                                   ? 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                                      [
                                                                      (0x3ffU 
                                                                       & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                                           << 0xeU) 
                                                                          | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                                             >> 0x12U)))] 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                      [
                                                      (0x3ffU 
                                                       & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                           << 0xeU) 
                                                          | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                             >> 0x12U)))]))
                                                   : 0U))
                                                 : 
                                                ((0x8000U 
                                                  & vlTOPp->pipeline_cpu__DOT__mem[3U])
                                                  ? 
                                                 vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                                                 [(0x3ffU 
                                                   & ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                       << 0xeU) 
                                                      | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                         >> 0x12U)))]
                                                  : 0U)));
    vlTOPp->pipeline_cpu__DOT__stall_by_load_use = 
        (((vlTOPp->pipeline_cpu__DOT__ex[3U] >> 0x1aU) 
          & (0U != (0x1fU & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                              << 0x16U) | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                           >> 0xaU)))))
          ? ((((0x1fU & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                          << 0x16U) | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                       >> 0xaU))) == 
               (0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                          << 0x11U) | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                       >> 0xfU)))) 
              | ((0x1fU & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                            << 0x16U) | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                         >> 0xaU))) 
                 == (0x1fU & ((vlTOPp->pipeline_cpu__DOT__id[2U] 
                               << 0xcU) | (vlTOPp->pipeline_cpu__DOT__id[1U] 
                                           >> 0x14U)))))
              ? 1U : 0U) : 0U);
    vlTOPp->pipeline_cpu__DOT__alu_control = ((0x10000000U 
                                               & vlTOPp->pipeline_cpu__DOT__ex[3U])
                                               ? ((0x1000U 
                                                   & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                   ? 
                                                  ((0x800U 
                                                    & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                    ? 
                                                   ((0x400U 
                                                     & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((0x400U 
                                                     & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                     ? 
                                                    ((0U 
                                                      == 
                                                      (0x7fU 
                                                       & ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                           << 0x1dU) 
                                                          | (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                             >> 3U))))
                                                      ? 9U
                                                      : 0xbU)
                                                     : 3U))
                                                   : 
                                                  ((0x800U 
                                                    & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                    ? 
                                                   ((0x400U 
                                                     & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                     ? 0xeU
                                                     : 6U)
                                                    : 
                                                   ((0x400U 
                                                     & vlTOPp->pipeline_cpu__DOT__ex[4U])
                                                     ? 7U
                                                     : 
                                                    (((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                       >> 8U) 
                                                      & (0x33U 
                                                         == 
                                                         (0x7fU 
                                                          & ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                              << 0x13U) 
                                                             | (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                                >> 0xdU)))))
                                                      ? 6U
                                                      : 2U))))
                                               : ((1U 
                                                   & (IData)(vlTOPp->pipeline_cpu__DOT__alu_op))
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->pipeline_cpu__DOT__ex[1U])
                                                    ? 0xeU
                                                    : 6U)
                                                   : 2U));
    vlTOPp->pipeline_cpu__DOT__forward_a = ((((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                               >> 8U) 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                      << 0x17U) 
                                                     | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                        >> 9U))))) 
                                             & ((0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                     << 0x17U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                       >> 9U))) 
                                                == 
                                                (0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                       >> 0x14U)))))
                                             ? 2U : 
                                            ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                >> 5U) 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                       << 0x1aU) 
                                                      | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                         >> 6U))))) 
                                              & ((0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U))) 
                                                 == 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                      << 0xcU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                        >> 0x14U)))))
                                              ? 1U : 0U));
    vlTOPp->pipeline_cpu__DOT__forward_b = ((((vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                               >> 8U) 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                      << 0x17U) 
                                                     | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                        >> 9U))))) 
                                             & ((0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                     << 0x17U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__mem[3U] 
                                                       >> 9U))) 
                                                == 
                                                (0x1fU 
                                                 & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     << 0x11U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                       >> 0xfU)))))
                                             ? 2U : 
                                            ((((vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                >> 5U) 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                       << 0x1aU) 
                                                      | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                         >> 6U))))) 
                                              & ((0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                        >> 6U))) 
                                                 == 
                                                 (0x1fU 
                                                  & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                      << 0x11U) 
                                                     | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                        >> 0xfU)))))
                                              ? 1U : 0U));
    vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 = ((0U == (IData)(vlTOPp->pipeline_cpu__DOT__forward_a))
                                               ? ((
                                                   vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                                   << 0xcU) 
                                                  | (vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                     >> 0x14U))
                                               : ((2U 
                                                   == (IData)(vlTOPp->pipeline_cpu__DOT__forward_a))
                                                   ? 
                                                  ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                    << 0x10U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                      >> 0x10U))
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->pipeline_cpu__DOT__forward_a))
                                                    ? 
                                                   ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                     << 0x15U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                       >> 0xbU))
                                                    : 
                                                   ((vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                       >> 0x14U)))));
    vlTOPp->pipeline_cpu__DOT__alu_fwd_in2 = ((0U == (IData)(vlTOPp->pipeline_cpu__DOT__forward_b))
                                               ? ((
                                                   vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                   << 0xcU) 
                                                  | (vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                     >> 0x14U))
                                               : ((2U 
                                                   == (IData)(vlTOPp->pipeline_cpu__DOT__forward_b))
                                                   ? 
                                                  ((vlTOPp->pipeline_cpu__DOT__mem[5U] 
                                                    << 0x10U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__mem[4U] 
                                                      >> 0x10U))
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->pipeline_cpu__DOT__forward_b))
                                                    ? 
                                                   ((vlTOPp->pipeline_cpu__DOT__wb[4U] 
                                                     << 0x15U) 
                                                    | (vlTOPp->pipeline_cpu__DOT__wb[3U] 
                                                       >> 0xbU))
                                                    : 
                                                   ((vlTOPp->pipeline_cpu__DOT__ex[6U] 
                                                     << 0xcU) 
                                                    | (vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                                       >> 0x14U)))));
    vlTOPp->pipeline_cpu__DOT__alu_in1 = ((0x40U & 
                                           vlTOPp->pipeline_cpu__DOT__ex[1U])
                                           ? ((vlTOPp->pipeline_cpu__DOT__ex[8U] 
                                               << 0xcU) 
                                              | (vlTOPp->pipeline_cpu__DOT__ex[7U] 
                                                 >> 0x14U))
                                           : vlTOPp->pipeline_cpu__DOT__alu_fwd_in1);
    vlTOPp->pipeline_cpu__DOT__alu_in2 = ((3U == (3U 
                                                  & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                      << 3U) 
                                                     | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                        >> 0x1dU))))
                                           ? ((vlTOPp->pipeline_cpu__DOT__ex[5U] 
                                               << 0xcU) 
                                              | (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                 >> 0x14U))
                                           : ((1U == 
                                               (3U 
                                                & ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                    << 3U) 
                                                   | (vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                      >> 0x1dU))))
                                               ? ((
                                                   vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->pipeline_cpu__DOT__ex[2U] 
                                                     >> 8U))
                                               : vlTOPp->pipeline_cpu__DOT__alu_fwd_in2));
    vlTOPp->pipeline_cpu__DOT__bu_unsigned_comparison 
        = (vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 < vlTOPp->pipeline_cpu__DOT__alu_fwd_in2);
    vlTOPp->pipeline_cpu__DOT__alu_result = ((8U & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                              ? ((4U 
                                                  & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    + vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                    : 
                                                   ((vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                     < vlTOPp->pipeline_cpu__DOT__alu_in2) 
                                                    << 0x1fU))
                                                   : 
                                                  (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                   + vlTOPp->pipeline_cpu__DOT__alu_in2))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,32, vlTOPp->pipeline_cpu__DOT__alu_in1, vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     : 
                                                    (- 
                                                     (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                      >> 0x1fU)))
                                                    : 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    + vlTOPp->pipeline_cpu__DOT__alu_in2))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     ? 
                                                    (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                     >> vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     : 0U)
                                                    : 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    + vlTOPp->pipeline_cpu__DOT__alu_in2))))
                                              : ((4U 
                                                  & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     ? 
                                                    (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                     << vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                     : 0U)
                                                    : 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    - vlTOPp->pipeline_cpu__DOT__alu_in2))
                                                   : 
                                                  (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                   + vlTOPp->pipeline_cpu__DOT__alu_in2))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    ^ vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                    : 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    + vlTOPp->pipeline_cpu__DOT__alu_in2))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__alu_control))
                                                    ? 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    | vlTOPp->pipeline_cpu__DOT__alu_in2)
                                                    : 
                                                   (vlTOPp->pipeline_cpu__DOT__alu_in1 
                                                    & vlTOPp->pipeline_cpu__DOT__alu_in2)))));
    vlTOPp->pipeline_cpu__DOT__branch_taken = (1U & 
                                               (((((vlTOPp->pipeline_cpu__DOT__ex[3U] 
                                                    >> 0x1fU) 
                                                   & ((0U 
                                                       == 
                                                       (vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                                        - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2))
                                                       ? 1U
                                                       : 0U)) 
                                                  | (vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     & (~ 
                                                        ((0U 
                                                          == 
                                                          (vlTOPp->pipeline_cpu__DOT__alu_fwd_in1 
                                                           - vlTOPp->pipeline_cpu__DOT__alu_fwd_in2))
                                                          ? 1U
                                                          : 0U)))) 
                                                 | ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                     >> 1U) 
                                                    & (IData)(vlTOPp->pipeline_cpu__DOT__bu_unsigned_comparison))) 
                                                | ((vlTOPp->pipeline_cpu__DOT__ex[4U] 
                                                    >> 2U) 
                                                   & (~ (IData)(vlTOPp->pipeline_cpu__DOT__bu_unsigned_comparison)))));
    vlTOPp->pipeline_cpu__DOT__id_flush = (1U & (((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                                   ? 1U
                                                   : 0U) 
                                                 | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    >> 3U)));
    vlTOPp->pipeline_cpu__DOT__if_flush = (1U & ((((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                                    ? 1U
                                                    : 0U) 
                                                  | (0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->pipeline_cpu__DOT__id[1U]))) 
                                                 | (vlTOPp->pipeline_cpu__DOT__ex[1U] 
                                                    >> 3U)));
    vlTOPp->pipeline_cpu__DOT__pc_next_sel = ((IData)(vlTOPp->pipeline_cpu__DOT__branch_taken)
                                               ? 3U
                                               : ((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->pipeline_cpu__DOT__id[1U]))
                                                   ? 2U
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->pipeline_cpu__DOT__ex[1U])
                                                    ? 1U
                                                    : 0U)));
    vlTOPp->pipeline_cpu__DOT__pc_next = ((3U == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
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
                                               : ((1U 
                                                   == (IData)(vlTOPp->pipeline_cpu__DOT__pc_next_sel))
                                                   ? vlTOPp->pipeline_cpu__DOT__alu_result
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlTOPp->pipeline_cpu__DOT__pc_curr))));
}

void Vpipeline_cpu::_eval(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_eval\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_b)) & (IData)(vlTOPp->__Vclklast__TOP__reset_b)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_b)) & (IData)(vlTOPp->__Vclklast__TOP__reset_b)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_b = vlTOPp->reset_b;
}

VL_INLINE_OPT QData Vpipeline_cpu::_change_request(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_change_request\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vpipeline_cpu::_change_request_1(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_change_request_1\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vpipeline_cpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_b & 0xfeU))) {
        Verilated::overWidthError("reset_b");}
}
#endif  // VL_DEBUG
