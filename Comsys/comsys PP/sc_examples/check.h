//------------------------------------------------------------------
// 4-bits adder checker module
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef CHECK_H
#define CHECK_H

#include <systemc.h>

#include <iostream>
using namespace std;       
                                
SC_MODULE(check) {
    sc_in<bool> clk;
    sc_in<sc_uint<16> > ain, bin, result;
    sc_in<sc_uint<4> > op;
    sc_in<bool> ci;
    sc_in<bool> co;
    sc_in<bool> oflag, zflag;

    sc_uint<16> sumc;

    void pc1() {    

        sumc=ain.read() + bin.read() + ci.read();

        if (oflag.read()==true) { 
            cout << "overflow value" << endl;
        }
        else if (zflag.read()==true) { 
            cout << "zero value" << endl;   
        }
        else {
            if (op.read() == 0)
                cout << "plus";
            else {
                cout << "minus";
            }
            cout << "op : " << op.read() << ", " << ain.read() << " with " << bin.read() << " + " << ci.read() << " =" << result.read()+co.read()*16 << "\n"; 
            // if (sumc(3,0)==result.read() && co==sumc[4]) {
            //     cout << " Passed" << endl;
            // } else {
            //     cout << " Failed, expected sum=" << sumc(3,0) << " co=" << sumc[4] << endl;
            // }
        }

    }

    SC_CTOR(check) {     
        SC_METHOD(pc1);                     
        sensitive << clk.pos();
        dont_initialize();
    }
};
#endif

