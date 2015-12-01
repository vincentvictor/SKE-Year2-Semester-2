#ifndef CONV_H
#define CONV_H

#include <systemc.h>
#include <math.h>
#include <bitset>

SC_MODULE(Conv) {
	sc_in<float> fin;
	sc_out<sc_uint<32> > fout;
	
	void p1(){
		sc_uint<32> temp1; 
		int index = 31;
		
		if( fin.read() < 0 ) {
			temp1[index--] = 1;
		}
		else {
			index--;
		}
		
		int n = 0; 
		int temp2 = 1; 
		while( fin.read() >= temp2 ) { // integer before point
			if( fin.read() > temp2 ) {
				temp2 = temp2 * 2;
				n++;
			}
		}
	
		//exponent 
		int exponent = 127 + n - 1; /// ex 
		sc_uint<8> exp = exponent;
		std::bitset<8> x(exp);
		
		for(int i = 7 ; i >= 0 ; i--) {
			temp1[index--] = exp[i];
		}
		
		sc_uint<23> mantissa; // Convert the mantissa into decimal using the last 23 bits
		float value = ( fin.read()/pow(2, n-1) ) - 1;   // value = (fin / 2^n-1) - 1
		
		for(int i = 22 ; i >= 0 ; i--) {
			value *= 2;
			if( value >= 1 ) {
				mantissa[i] = 1;
				value = value - 1;
			}
		}
		
		std::bitset<23> y(mantissa);
		
		for(int i = 22 ; i >=0 ; i--){
			temp1[index--] = mantissa[i];
		}
		fout.write(temp1);
	}
	

	SC_CTOR(Conv) {     
        SC_METHOD(p1);  
        sensitive << fin; 
    }
};
#endif

