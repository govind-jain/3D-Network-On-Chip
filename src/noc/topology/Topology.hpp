#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP

#include "../types/types.hpp"
#include "../node/node.hpp"
#include "TopologyConfig.hpp"
#include <bits/stdc++.h>

using namespace std;

class c_Topology {

protected:
    int m_NumberOfNodes;
    t_AdjacencyList m_AdjacencyList;
    vector<c_Node*> m_ListOfNodePointers;

private:
    void f_SetNumberOfNodes(int p_NumberOfNodes);
    void f_SetAdjacencyList(t_AdjacencyList p_AdjacencyList);
    void f_SetListOfNodePointers();
    void f_SetCoordinatesOfNodePointers(vector<t_Coordinates> p_CoordinatesList);
    t_Axis f_GetAxisOfDifference(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2);
    void f_SetConnections();

public:
    explicit c_Topology(c_TopologyConfig *T);
};

#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_HPP
