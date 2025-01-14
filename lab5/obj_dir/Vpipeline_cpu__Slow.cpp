// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpipeline_cpu.h for the primary calling header

#include "Vpipeline_cpu.h"
#include "Vpipeline_cpu__Syms.h"

//==========

VL_CTOR_IMP(Vpipeline_cpu) {
    Vpipeline_cpu__Syms* __restrict vlSymsp = __VlSymsp = new Vpipeline_cpu__Syms(this, name());
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vpipeline_cpu::__Vconfigure(Vpipeline_cpu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vpipeline_cpu::~Vpipeline_cpu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vpipeline_cpu::_initial__TOP__1(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_initial__TOP__1\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    VL_READMEM_N(true, 32, 1024, 0, std::string("dmem.mem")
                 , vlTOPp->pipeline_cpu__DOT__u_dmem_0__DOT__data
                 , 0, ~0ULL);
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x66696c65U;
    __Vtemp1[2U] = 0x726567U;
    VL_READMEM_N(true, 32, 32, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 , vlTOPp->pipeline_cpu__DOT__u_regfile_0__DOT__rf_data
                 , 0, ~0ULL);
    vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x400U, vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i)) {
        vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__data[(0x3ffU 
                                                        & vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i)] = 0U;
        vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i);
    }
    VL_READMEM_N(false, 32, 1024, 0, std::string("imem.mem")
                 , vlTOPp->pipeline_cpu__DOT__u_imem_0__DOT__data
                 , 0, ~0ULL);
}

void Vpipeline_cpu::_settle__TOP__4(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_settle__TOP__4\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vpipeline_cpu::_eval_initial(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_eval_initial\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_b = vlTOPp->reset_b;
}

void Vpipeline_cpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::final\n"); );
    // Variables
    Vpipeline_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vpipeline_cpu::_eval_settle(Vpipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_eval_settle\n"); );
    Vpipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vpipeline_cpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline_cpu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_b = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__pc_curr = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__pc_next = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__pc_next_sel = VL_RAND_RESET_I(2);
    pipeline_cpu__DOT__branch_taken = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96, pipeline_cpu__DOT__id);
    VL_RAND_RESET_W(276, pipeline_cpu__DOT__ex);
    VL_RAND_RESET_W(176, pipeline_cpu__DOT__mem);
    VL_RAND_RESET_W(171, pipeline_cpu__DOT__wb);
    pipeline_cpu__DOT__if_flush = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__branch = VL_RAND_RESET_I(4);
    pipeline_cpu__DOT__alu_op = VL_RAND_RESET_I(2);
    pipeline_cpu__DOT__isCompare = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__imm12 = VL_RAND_RESET_I(12);
    pipeline_cpu__DOT__imm32_J = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__stall_by_load_use = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__id_flush = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__rd_din = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__alu_control = VL_RAND_RESET_I(4);
    pipeline_cpu__DOT__forward_a = VL_RAND_RESET_I(2);
    pipeline_cpu__DOT__forward_b = VL_RAND_RESET_I(2);
    pipeline_cpu__DOT__alu_fwd_in1 = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__alu_fwd_in2 = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__alu_in1 = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__alu_in2 = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    pipeline_cpu__DOT__bu_unsigned_comparison = VL_RAND_RESET_I(1);
    pipeline_cpu__DOT__dmem_dout = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            pipeline_cpu__DOT__u_imem_0__DOT__data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            pipeline_cpu__DOT__u_dmem_0__DOT__data[__Vi0] = VL_RAND_RESET_I(32);
    }}
    VL_RAND_RESET_W(276, __Vdly__pipeline_cpu__DOT__ex);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
