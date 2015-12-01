//------------------------------------------------------------------
// Simple flipflop 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;

    void p1() {                                                           
        dout.write(din.read()); 
        //dout=din;          // Not recommended
    }

    SC_CTOR(dff) {
        SC_METHOD(p1);
        sensitive << clk.pos();
        //sensitive(clk.pos());  // not recommended
    }
};

