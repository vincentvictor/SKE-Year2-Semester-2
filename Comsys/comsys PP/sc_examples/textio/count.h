//------------------------------------------------------------------
// Simple example showing some textio usage  
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#ifndef COUNT_H
#define COUNT_H

#include <systemc.h>

#include <iostream>
#include <iomanip>
using namespace std;    

SC_MODULE(counter) {

    sc_in<bool >  clk;
    sc_in<sc_logic >  reset;
    sc_out<sc_int<4> > count;

    int cnt;

    void p1() {
        cout << "Release  -> " << sc_release()  << endl;
        cout << "Version  -> " << sc_version()  << endl;
    }

    void p2() {
        if ((reset.read() == 1)) {
            count.write(0);
            cout  << "numbers=" << 10 << hex << 11 << 12;
            cout  << 13 << 14 << dec << 15 << endl;
        } else {
            count.write((count.read()+1)&0xF);
            cout  << " nothing=" << count.read() << endl;
        }       
    }

    SC_CTOR(counter) {
        SC_THREAD(p1);
        SC_METHOD(p2);
        sensitive << clk.pos();
    }

};
#endif
