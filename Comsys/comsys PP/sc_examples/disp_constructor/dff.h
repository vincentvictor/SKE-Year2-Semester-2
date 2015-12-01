//------------------------------------------------------------------
// Simple Constructor/Simulator Test 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {

    void before_end_of_elaboration() {                                                            
        cout << "before_end_of_elaboration() called" << endl; 
    }

    void end_of_elaboration() {                                                           
        cout << "end_of_elaboration() called" << endl; 
    }


    void start_of_simulation() {                                                              
        cout << "start_of_simulation() called" << endl; 
    }

    void end_of_simulation() {                                                            
        cout << "end_of_simulation() called" << endl; 
    }


    dff(sc_module_name _n) : sc_module(_n) {
        cout << "dff:: Call Constructor for DFF" << endl;
    }

    ~dff() {
        cout << "dff:: Call Destructor for DFF" << endl;
    }


};

