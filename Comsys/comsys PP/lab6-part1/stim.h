#ifndef STIM_H
#define STIM_H

#include "systemc.h"
                                
SC_MODULE(stim) {
    sc_in<bool >  clk;
    sc_out<bool> enable;
    sc_out<bool> rw;
    sc_out<bool >  clr;
    sc_out<sc_uint<16> >  din;

    void ps1() {    
        //2 waits for passing the value
        wait();
        wait();

        clr.write(0);
        wait();

        clr.write(1);
        enable.write(1);
        rw.write(1);
        din.write("0b0000000000000011");
        cout << endl;
        wait();

        enable.write(1);
        rw.write(0);
        din.write("0b0000000000000100");
        cout << endl;
        wait();

        enable.write(1);
        rw.write(1);
        din.write("0b0000000000000001");
        cout << endl;
        wait();

        enable.write(1);
        rw.write(0);
        din.write("0b0000000000000011");
        cout << endl;
        wait();

        enable.write(1);
        rw.write(1);
        din.write("0b0000000000001111");
        cout << endl;
        wait();

        enable.write(1);
        rw.write(0);
        din.write("0b0000000000000011");
        cout << endl;
        wait();
        wait();

        sc_stop();  // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif