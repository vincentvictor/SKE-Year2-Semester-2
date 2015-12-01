//------------------------------------------------------------------
// Simple Counter Initialised during instantiation
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef COUNT_H
#define COUNT_H

#include <systemc.h>       

SC_MODULE(count) {

    sc_in<bool > clk;
    sc_out<int > dout;

    int cnt;

    void p1() {    
        dout.write(cnt++);  // simple counter 
    }

    count (sc_module_name _n, int _cnt) : sc_module(_n), cnt(_cnt) {

        SC_METHOD(p1);
        sensitive << clk.pos();
        dont_initialize();
    }

    //SC_CTOR(count) {
    count (sc_module_name _n) : sc_module(_n) {

        cnt=8;// init during default construction

        SC_METHOD(p1);
        sensitive << clk.pos();
        dont_initialize();
    }


    SC_HAS_PROCESS(count);// Required if SC_CTOR is not used but processes are

};
#endif
