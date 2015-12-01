//------------------------------------------------------------------
// Simple Counter + Initialised output port
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef COUNT_H
#define COUNT_H

#include <systemc.h>       

SC_MODULE(count) {

    sc_in<bool > clk;
    sc_inout<int > dout;

    void p1() {    
        dout.write(dout.read()+1);  // simple counter 
    }

    SC_CTOR(count) {

        dout.initialize(0x55);      // Initialise output port

        SC_METHOD(p1);
        sensitive << clk.pos();
        dont_initialize();
    }

};
#endif
