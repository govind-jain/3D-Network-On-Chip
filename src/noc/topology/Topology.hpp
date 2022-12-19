#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP

#include "../types/types.hpp"
#include "../node/node.hpp"
#include "TopologyConfig.hpp"
#include <bits/stdc++.h>

using namespace std;

class c_Topology{

private:
    int m_NumberOfNodes;
    vector<t_Coordinates> m_CoordinatesList;
    vector<c_Node*> m_ListOfNodePointers;

    void f_SetNumberOfNodes(int p_NumberOfNodes);
    void f_SetCoordinatesList(vector<t_Coordinates> p_CoordinatesList);
    void f_SetListOfNodePointers();
    t_Axis f_GetAxisOfDifference(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2);
    void f_SetConnections(t_AdjacencyList p_AdjacencyList);

public:
    explicit c_Topology(TopologyConfig *T);
};

#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
