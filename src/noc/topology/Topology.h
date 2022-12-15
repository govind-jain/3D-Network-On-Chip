#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H

#include <bits/stdc++.h>
#include <../node/node.h>
#include "TopologyConfig.h"

using namespace std;

class c_Topology{
private:
    int l_NumNodes;
    vector<t_Coordinate> l_Position;
    vector<c_Node*> l_Address;
public:
    explicit c_Topology(int p_NumNodes);
    void SetAddress(vector<c_Node*> p_Address);
    void SetPosition(vector<t_Coordinate> p_Position);
    explicit c_Topology(TopologyConfig *T);
};


#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGY_H
