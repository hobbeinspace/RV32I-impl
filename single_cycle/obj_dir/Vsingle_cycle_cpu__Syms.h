// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSINGLE_CYCLE_CPU__SYMS_H_
#define _VSINGLE_CYCLE_CPU__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vsingle_cycle_cpu.h"

// SYMS CLASS
class Vsingle_cycle_cpu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vsingle_cycle_cpu*             TOPp;
    
    // CREATORS
    Vsingle_cycle_cpu__Syms(Vsingle_cycle_cpu* topp, const char* namep);
    ~Vsingle_cycle_cpu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
