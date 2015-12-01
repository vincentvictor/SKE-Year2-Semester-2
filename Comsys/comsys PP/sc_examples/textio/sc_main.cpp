//------------------------------------------------------------------
// Simple Testbench for counter.h 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "count.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_logic > reset;
    sc_signal<sc_int<4> > count;

    sc_clock clk("clk",10,SC_NS,0.5,10,SC_NS,false);    // Create a clock signal
    
    counter DUT("counter");             // Instantiate Device Under Test, start at 32

    DUT.clk(clk);
    DUT.reset(reset);
    DUT.count(count);

    reset = SC_LOGIC_1;
    sc_start(20, SC_NS);                // Run simulation
    reset = SC_LOGIC_0;
    sc_start(180, SC_NS);               // Run simulation

    return 0;
}
