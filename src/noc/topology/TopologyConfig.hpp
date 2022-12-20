#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP

#include "../types/types.hpp"
#include <bits/stdc++.h>

class c_TopologyConfig{
private:
    int m_NumberOfNodes;
    vector<t_Coordinates> m_CoordinatesList;
    t_AdjacencyList m_AdjacencyList;
public:
    void f_SetTopologyFromInput();
    t_AdjacencyList f_GetAdjacencyList();
    vector<t_Coordinates> f_GetCoordinatesList();
    int f_GetNumberOfNodes();
};

#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP