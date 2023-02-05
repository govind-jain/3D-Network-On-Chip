#include "Start.hpp"
#include "../controller/NetworkController.hpp"

#define MAX_CLK_CYCLES 5 // TODO change number during real execution.

void c_Starter::f_InitializeSimulation() {
    for (int i = 0; i < MAX_CLK_CYCLES; ++i) {
        cout << "cycle number " << i << endl;
        c_NetworkController *NC = new c_NetworkController();
        NC->f_clockCycle();
    }

}
