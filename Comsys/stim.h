//------------------------------------------------------------------
// Simple 4-bits adder
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef STIM_H
#define STIM_H
#include <bitset>
#include <systemc.h>
                                
SC_MODULE(Stim) {
    sc_in<bool> clk;
    sc_in<sc_uint<32> > fout_s;
    sc_out<float> fin1 , fin2;
    

    void p2() {    

	fin1.write(11.625);
	fin2.write(19.50);	 
	wait();
	wait();
	
	std::bitset<32> result(fout_s.read());
	cout << "Result = "<< result << endl;
	
    }

    SC_CTOR(Stim) {  
        SC_THREAD(p2);                 
        sensitive << clk.pos();
    }
};
#endif

