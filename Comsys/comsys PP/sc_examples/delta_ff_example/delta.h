#include <systemc.h>

SC_MODULE(delta) {

    sc_in<bool >  clk;
    sc_in<bool >  din;
    sc_out<bool > dout;

    sc_signal<bool > q_s;
    sc_signal<bool > clk_s;

    void p1() {
        q_s.write(din.read());
    }
    void p2() {
        dout.write(q_s.read());
    }

    void comb_assignments() {
        clk_s.write(clk.read()); // delta delay!
    }

    SC_CTOR(delta) {
        SC_METHOD(p1);
        sensitive << clk.pos();
        SC_METHOD(p2);
        sensitive << clk_s.posedge_event();
        SC_METHOD(comb_assignments);
        sensitive << clk;
    }
};
