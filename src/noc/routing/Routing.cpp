#include "Routing.h"
#include "Floyd-Warshall.h"
using namespace std;


Routing::Routing(t_RoutingAlgorithm p_RoutingAlgorithm, TopologyConfig *T) {
    if (p_RoutingAlgorithm == E_FloydWarshall) {
        f_GetRoutingTable(T->f_GetNeighbours());
    }
}
