#ifndef ADD_H
#define ADD_H

#include <systemc.h>
#include <math.h>
#include <bitset>

SC_MODULE(Add) {
	sc_in<sc_uint<32> > fin1, fin2;
	sc_out<sc_uint<32> > fout;
	
	void p1(){
		sc_uint<25> temp1, temp2;
		sc_uint<32> f1 = fin1.read();
		sc_uint<32> f2 = fin2.read();
		sc_uint<8> exp1, exp2;
		//=========================================
		for(int i = 0 ; i < 23 ; i++) {
			temp1[i] = f1[i];
			temp2[i] = f2[i];
		}
		
		for(int i = 0 ; i < 8 ; i++){ 
			exp1[i] = f1[i+23];
			exp2[i] = f2[i+23];		
		}
		
		temp1[23] = 1;
		temp2[23] = 1;
		//=========================================
		int ex1 = exp1 - 127;
		int ex2 = exp2 - 127;
		int tempExp;
		if(ex1 > ex2) {
			tempExp = ex1 - ex2;				
			temp2 = temp2 >> tex;
			ex2 = ex1;			
		}
		else if(ex2 > ex1 ) {
			tempEx = ex2 - ex1;
			temp1 = temp1 >> tex;
			ex1 = ex2;
		}
		//=========================================
		sc_uint<25> result = temp1 + temp2;
		
		if(result[24] == 1){
			result = result >> 1;
			ex1 += 1;		
		}
		sc_uint<32> result_s;
		int index = 31;
		
		if(result < 0) {
			result_s[index--] = 1;
		}
		else {
			index--;
		}
		//=========================================
		int newExponent = 127 + ex1;
		sc_uint<8> newExp = newExponent;
		
		for(int i = 7 ; i >= 0 ; i--){
			result_s[index--] = newExp[i];
		}
		
		sc_uint<23> mantissa;
		
		for(int i = 0 ; i < 23 ; i++ ){
			result_s[i] = result[i];
		}
		fout.write(result_s);
	}
	
	SC_CTOR(Add) {     
        SC_METHOD(p1);  
        sensitive << fin1 << fin2; 
    }
};
#endif

