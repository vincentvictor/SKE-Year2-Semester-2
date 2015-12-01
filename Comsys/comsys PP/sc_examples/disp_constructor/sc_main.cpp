//------------------------------------------------------------------
// Testbench for constructor test 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "dff.h"

int sc_main(int argc, char* argv[])
{

    cout << "----------- Start of sc_main()---------------- " << endl;

    dff DUT("dff");                     // Instantiate Device Under Test
    
    cout << "Just after instantating dff, just before sc_start()" << endl;

    sc_start(100, SC_NS);               // Run simulation
    
    cout << "Just before sc_stop(), just after sc_start()" << endl;

    sc_stop();

    cout << "------------- End of sc_main()-----------------" << endl;
    return 0;
}
