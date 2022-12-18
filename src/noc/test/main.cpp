#include "TopologyConfig.h"
#include "Topology.h"
#include "../routing/Routing.h"
using namespace std;

int main() {
    TopologyConfig* T = new TopologyConfig();
    T->f_SetTopology();

    // 5 Layers
    int NumLayers = 5;
    for (int i = 0; i < NumLayers; ++i) {
        c_Topology* l_topology = new c_Topology(T);
    }
    Routing *R = new Routing(E_FloydWarshall, T);


    return 0;
}
