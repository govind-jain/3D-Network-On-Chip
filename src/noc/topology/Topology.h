#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H

#include <bits/stdc++.h>
#include <../node/node.h>
#include "../types/types.h"
#include "TopologyConfig.h"

using namespace std;

class c_Topology{
private:
    int m_NumNodes;
    vector<t_Coordinate> m_Position;
    vector<c_Node*> m_Address;
public:
    void SetAddress(vector<c_Node*> p_Address);
    void SetPosition(vector<t_Coordinate> p_Position);
    explicit c_Topology(TopologyConfig *T);
    t_AxisType f_GetAxis(int &i, int &j);
};


#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H
