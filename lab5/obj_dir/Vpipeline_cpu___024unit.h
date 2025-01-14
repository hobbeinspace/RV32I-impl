// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpipeline_cpu.h for the primary calling header

#ifndef _VPIPELINE_CPU___024UNIT_H_
#define _VPIPELINE_CPU___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vpipeline_cpu__Syms;
class Vpipeline_cpu_VerilatedVcd;


//----------

VL_MODULE(Vpipeline_cpu___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vpipeline_cpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vpipeline_cpu___024unit);  ///< Copying not allowed
  public:
    Vpipeline_cpu___024unit(const char* name = "TOP");
    ~Vpipeline_cpu___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vpipeline_cpu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
