#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>
                                
SC_MODULE(adder) {
    sc_out<sc_uint<16> > result;
    sc_in<sc_uint<16> > ain, bin;
    sc_in<bool> ci;
    sc_out<bool> co;
    sc_out<bool> zflag, oflag;
    sc_in<sc_uint<4> > op;

    bool coA;
    sc_uint<16> res_s;

    // 1-bit ripple carry fulladder, note the cof reference bool&
    bool fulladder(bool a, bool b, bool cif, bool& cof) {
        bool sumr;
        sumr =(a ^ b) ^ cif;
        cof=(a & b) | ((a ^ b) & cif);      
        return sumr;    
    }

    bool isZero(sc_uint<16> res_s) {
        int i;
        for (i = 0 ; i < 16 ; i++) {
            if (res_s[i] == 1)
                return false;
        }
        return true;
    }

    void p1() {
         if(op.read() == 0) { //add
            int i;
            res_s[0]=fulladder(ain.read()[0],bin.read()[0],ci.read(), coA);
            for (i = 1 ; i < 16 ; i++) {
                res_s[i] = fulladder(ain.read()[i],bin.read()[i],coA,coA);
            }
            cout << "plus : " << ain.read() << " + " << bin.read() << " = " << res_s << endl;
        } 
        else if (op.read() == 1) { //sub
            int i;
            res_s[0]=fulladder(ain.read()[0],~bin.read()[0], 1, coA);
            for (i = 1 ; i < 16 ; i++) {
                res_s[i] = fulladder(ain.read()[i],~bin.read()[i],coA,coA);
            }
            cout << "minus : " << ain.read() << " - " << bin.read() << " = " << res_s << endl;
        } 
        else if (op.read() == 2) { //xor
            cout << "xor : " << ain.read() << " xor " << bin.read() << " = " << (ain.read()^bin.read()) << endl;
        } 
        else if (op.read() == 3) { //and
            cout << "and : " << ain.read() << " and " << bin.read() << " = " << (ain.read()&bin.read()) << endl;
        } 
        else if (op.read() == 4) { //or
            cout << "or : " << ain.read() << " or " << bin.read() << " = " << (ain.read()|bin.read()) << endl;
        } 
        else if (op.read() == 5) { //not
            res_s = ~ain.read();
            cout << "not : " << "~" << ain.read() << " = " << res_s << endl;
        } 
        else if (op.read() == 6) { //slt
            if (ain.read() < bin.read()) res_s = 1;
            else res_s = 0;
            cout << "slt : " << ain.read() << " slt " << bin.read() << " = " << res_s << endl;
        }

        //write overflowflag
        oflag.write(coA); 
        
        //check zeroflag
        if (isZero(res_s)) zflag.write(1); 
        else zflag.write(0);

        //writing result
        result.write(res_s);
        co.write(coA);
    }

    SC_CTOR(adder) {
        
        SC_METHOD(p1);  
        sensitive << ain << bin << ci << op; 
    }
};
#endif

