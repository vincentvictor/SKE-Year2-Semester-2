#include <systemc.h>

#include "adder.h"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_uint<16> > ain, bin, result;
    sc_signal<bool> ci, co, zflag, oflag;
    sc_signal<sc_uint<4> > op;

    sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal

    adder DUT("adder");                 // Instantiate Device Under Test
    DUT.ain(ain);                       // Connect ports
    DUT.bin(bin);
    DUT.ci(ci); 
    DUT.result(result);
    DUT.co(co);
    DUT.zflag(zflag);
    DUT.oflag(oflag);
    DUT.op(op);

    stim STIM("stimulus");              // Instantiate stimulus generator
    STIM.clk(clk);  
    STIM.ain(ain);
    STIM.bin(bin);
    STIM.ci(ci);
    STIM.op(op);

    sc_start(100, SC_NS);               // Run simulation for 100 ns
    // sc_start(100, SC_NS);               // Run another  100 ns

    return 0;                           // Return OK, no errors.
}
