//------------------------------------------------------------------
// Simple Testbench for dff flipflop file
//
// Tracing performed locally in dff SC_THREAD process.
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "dff.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> din, dout;

    sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal

    dff DUT("dff");                     // Instantiate Device Under Test
    
    DUT.clk(clk);                       // Connect ports
    DUT.din(din);
    DUT.dout(dout);

    sc_start(6, SC_NS);                 // Run simulation
    din=true;                           
    sc_start(14, SC_NS);                // Run simulation
    din=false;                          
    sc_start(100, SC_NS);               // Run simulation

    return 0;
}
