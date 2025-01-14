// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsingle_cycle_cpu__Syms.h"
#include "Vsingle_cycle_cpu.h"



// FUNCTIONS
Vsingle_cycle_cpu__Syms::Vsingle_cycle_cpu__Syms(Vsingle_cycle_cpu* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
