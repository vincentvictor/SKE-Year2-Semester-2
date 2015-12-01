//------------------------------------------------------------------
// Simple example showing .range() and concat methods  
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef ROR_H
#define ROR_H

#include <systemc.h>       

SC_MODULE(ror) {

    sc_in<bool > clk;
    sc_in<sc_uint<8> > din;
    sc_out<sc_uint<8> > dout1;
    sc_out<sc_uint<8> > dout2;


    void p1() { 
        dout1.write( concat(din.read()[0],din.read().range(7,1)) );     // OK
        dout2.write( concat(din.read()(3,0),din.read().range(7,4)) );
    }


    SC_CTOR(ror) {

        dout1.initialize(0);    // init during construction
        dout2.initialize(0);                

        SC_METHOD(p1);
        sensitive << clk.pos();
        dont_initialize();

    }

};
#endif
