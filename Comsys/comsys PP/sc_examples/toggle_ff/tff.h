//------------------------------------------------------------------
// Toggle FlipFlop example showing the usage of signals and variables 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef TFF_H
#define TFF_H

#include <systemc.h>       

SC_MODULE(tff) {

    sc_in<bool >  clk;
    sc_out<bool > dout1;
    sc_out<bool > dout2;

    sc_signal<bool> sig1;
    bool var2;

    void p1() {             // using signals
        sig1.write(!sig1.read());
        dout1.write(sig1.read());
    }

    void p2() {             // using variables
        var2=!var2;
        dout2.write(var2);
    }

    SC_CTOR(tff) {

        sig1.write(true);   // init during construction
        var2=false;         

        SC_METHOD(p1);
        sensitive << clk.pos();
        dont_initialize();

        SC_METHOD(p2);
        sensitive << clk.pos();
        dont_initialize();
    }

};
#endif
