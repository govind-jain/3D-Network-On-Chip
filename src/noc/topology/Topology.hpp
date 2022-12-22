#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP

#include "../types/types.hpp"
#include "../node/node.hpp"
#include "TopologyConfig.hpp"
#include <bits/stdc++.h>

using namespace std;

class c_Topology {

private:
    int m_NumberOfSwitches;
    t_AdjacencyList m_AdjacencyList;
    vector<c_Node*> m_ListOfSwitchPointers;

    void f_SetNumberOfSwitches(int p_NumberOfSwitches);
    void f_SetAdjacencyList(t_AdjacencyList p_AdjacencyList);
    void f_SetListOfSwitchPointers();
    void f_SetCoordinatesOfSwitches(vector<t_Coordinates> p_CoordinatesList);
    t_Axis f_GetAxisOfDifferenceOfSwitches(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2);
    void f_SetConnections();

public:
    c_Topology(c_TopologyConfig *T);
    int f_GetNumberOfSwitches();
    c_Node* f_GetSwitchPointer(t_SwitchId p_SwitchId);
    t_AdjacencyListOfSwitch f_AdjacencyListOfSwitch(t_SwitchId p_SwitchId);
};

#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
