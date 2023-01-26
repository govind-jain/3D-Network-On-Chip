#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP

#include "../types/types.hpp"
#include <bits/stdc++.h>

class c_TopologyConfig{
private:
    int m_NumberOfSwitches;
    t_CoordinatesList m_CoordinatesListOfSwitches;
    t_AdjacencyListOfSwitches m_AdjacencyListOfSwitches;
public:
    void f_SetTopologyFromInput();
    t_AdjacencyListOfSwitches f_GetAdjacencyListOfSwitches();
    t_CoordinatesList f_GetCoordinatesListOfSwitches();
    int f_GetNumberOfSwitches();
};

#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_CONFIG_HPP