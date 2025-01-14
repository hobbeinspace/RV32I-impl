// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VPIPELINE_CPU_H_
#define _VPIPELINE_CPU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vpipeline_cpu__Syms;
class Vpipeline_cpu_VerilatedVcd;


//----------

VL_MODULE(Vpipeline_cpu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_b,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ pipeline_cpu__DOT__pc_next_sel;
    CData/*0:0*/ pipeline_cpu__DOT__branch_taken;
    CData/*0:0*/ pipeline_cpu__DOT__if_flush;
    CData/*3:0*/ pipeline_cpu__DOT__branch;
    CData/*1:0*/ pipeline_cpu__DOT__alu_op;
    CData/*0:0*/ pipeline_cpu__DOT__isCompare;
    CData/*0:0*/ pipeline_cpu__DOT__stall_by_load_use;
    CData/*0:0*/ pipeline_cpu__DOT__id_flush;
    CData/*3:0*/ pipeline_cpu__DOT__alu_control;
    CData/*1:0*/ pipeline_cpu__DOT__forward_a;
    CData/*1:0*/ pipeline_cpu__DOT__forward_b;
    CData/*0:0*/ pipeline_cpu__DOT__bu_unsigned_comparison;
    SData/*11:0*/ pipeline_cpu__DOT__imm12;
    IData/*31:0*/ pipeline_cpu__DOT__pc_curr;
    IData/*31:0*/ pipeline_cpu__DOT__pc_next;
    IData/*31:0*/ pipeline_cpu__DOT__imm32_J;
    IData/*31:0*/ pipeline_cpu__DOT__rd_din;
    IData/*31:0*/ pipeline_cpu__DOT__alu_fwd_in1;
    IData/*31:0*/ pipeline_cpu__DOT__alu_fwd_in2;
    IData/*31:0*/ pipeline_cpu__DOT__alu_in1;
    IData/*31:0*/ pipeline_cpu__DOT__alu_in2;
    IData/*31:0*/ pipeline_cpu__DOT__alu_result;
    IData/*31:0*/ pipeline_cpu__DOT__dmem_dout;
    IData/*31:0*/ pipeline_cpu__DOT__u_imem_0__DOT__unnamedblk1__DOT__i;
    WData/*95:0*/ pipeline_cpu__DOT__id[3];
    WData/*275:0*/ pipeline_cpu__DOT__ex[9];
    WData/*175:0*/ pipeline_cpu__DOT__mem[6];
    WData/*170:0*/ pipeline_cpu__DOT__wb[6];
    IData/*31:0*/ pipeline_cpu__DOT__u_imem_0__DOT__data[1024];
    IData/*31:0*/ pipeline_cpu__DOT__u_regfile_0__DOT__rf_data[32];
    IData/*31:0*/ pipeline_cpu__DOT__u_dmem_0__DOT__data[1024];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset_b;
    WData/*275:0*/ __Vdly__pipeline_cpu__DOT__ex[9];
    CData/*0:0*/ __Vm_traceActivity[4];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vpipeline_cpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vpipeline_cpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vpipeline_cpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vpipeline_cpu();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vpipeline_cpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vpipeline_cpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vpipeline_cpu__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vpipeline_cpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vpipeline_cpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vpipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vpipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vpipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vpipeline_cpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vpipeline_cpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vpipeline_cpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vpipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
