// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vpipeline_cpu__Syms.h"
#include "Vpipeline_cpu.h"
#include "Vpipeline_cpu___024unit.h"



// FUNCTIONS
Vpipeline_cpu__Syms::Vpipeline_cpu__Syms(Vpipeline_cpu* topp, const char* namep)
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
