//------------------------------------------------------------------
// Simple Testbench for dff flipflop file
//
// Tracing performed locally in dff module constructor.
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

    DUT.din(din);                       // Connect ports
    DUT.dout(dout);
    DUT.clk(clk);

    sc_start(31, SC_NS);                // Run simulation
    din=true;                           
    sc_start(31, SC_NS);                // Run simulation
    din=false;                          
    sc_start(31, SC_NS);                // Run simulation


    return 0;
}
