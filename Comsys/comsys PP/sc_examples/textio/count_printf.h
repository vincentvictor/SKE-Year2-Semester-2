//------------------------------------------------------------------
// Simple example showing printf usage   
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef COUNT_H
#define COUNT_H

#include <systemc.h>

SC_MODULE(count) {

    sc_in<bool >  clk;
    sc_in<sc_logic >  reset;
    sc_out<sc_int<4> > cout;

    int cnt;

    void p1() {
        if ((reset.read() == 1)) {
            cout.write(0);
        } else {
            cout.write(cout.read()+1);
            printf("Counter in unsigned=%03u signed=%03d hex=%03X\n",(cout.read().to_uint())&0xF,cout.read().to_int(),(cout.read().to_uint())&0xF);
        }       
    }

    SC_CTOR(count) {
        SC_METHOD(p1);
        sensitive << clk.pos();
    }

};
#endif
