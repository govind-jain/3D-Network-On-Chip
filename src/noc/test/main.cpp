#include "TopologyConfig.hpp"
#include "../routing/Routing.hpp"
#include "../routing/ShortestPathRouting.hpp"
using namespace std;

int main() {
    c_TopologyConfig* T = new c_TopologyConfig();
    cout<<"Building Topology"<<endl;
    T->f_SetTopologyFromInput();
    cout<<"Built Topology"<<endl;

    // 5 Layers
//    int NumLayers = 5;
//    for (int i = 0; i < NumLayers; ++i) {
//        c_Topology* l_topology = new c_Topology(T);
//    }

    cout<<"Building Routing Tables"<<endl;
    c_Routing *R = new c_ShortestPathRouting(T);
    cout<<"Built Routing Tables"<<endl;

    cout<<"Print Routing Path"<<endl;
    R->f_GetRoutingPath(0, 5);
    R->f_GetRoutingPath(5, 0);
    cout<<"Printed Routing Path"<<endl;

    return 0;
}
