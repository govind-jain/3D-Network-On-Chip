#ifndef INC_3D_NETWORK_ON_CHIP_SHORTEST_PATH_ROUTING_H
#define INC_3D_NETWORK_ON_CHIP_SHORTEST_PATH_ROUTING_H

#include "../types/types.hpp"
#include "../topology/Topology.hpp"
#include "RoutingTable.hpp"
#include <bits/stdc++.h>

using namespace std;
#define INF 100000000

class c_ShortestPathRouting : virtual public c_Topology, virtual public c_RoutingTable{

    private:
        t_AdjacencyMatrix m_AdjacencyMatrix;

        t_Distance f_FindDistanceBetweenSwitches(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2);
        void f_SetAdjacencyMatrix();
        t_AdjacencyMatrix f_GetAllPairsShortestPath();

    public:

};

#endif //INC_3D_NETWORK_ON_CHIP_SHORTEST_PATH_ROUTING_H
