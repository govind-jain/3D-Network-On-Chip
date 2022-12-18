#ifndef INC_3D_NETWORK_ON_CHIP_ROUTING_H
#define INC_3D_NETWORK_ON_CHIP_ROUTING_H

#include <bits/stdc++.h>
#include "../types/types.h"
#include "../topology/TopologyConfig.h"
#include "Floyd-Warshall.h"
using namespace std;

class Routing{
public:
    Routing(t_RoutingAlgorithm p_RoutingAlgorithm, TopologyConfig *T);

};

#endif //INC_3D_NETWORK_ON_CHIP_ROUTING_H
