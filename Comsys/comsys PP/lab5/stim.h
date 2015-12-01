#ifndef STIM_H
#define STIM_H

#include <systemc.h>

SC_MODULE(stim) {
	sc_in<bool> clk;
	sc_out<bool> rst;
    sc_out<sc_uint<16> > a, b;

    void ps1() { 
        a.write("0b00000000000000000000000000000101");
		b.write("0b00000000000000000000000000000111");
        rst.write(false);
        wait();
        
        sc_stop();                          // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif