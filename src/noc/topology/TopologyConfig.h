#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H

#include "../types/types.h"

class TopologyConfig{
private:
    int m_NumNodes;
    vector<t_Coordinate> m_Position;
    t_AdjacencyList m_Neighbours;
public:
    void f_SetTopology();
    t_AdjacencyList f_GetNeighbours();
    vector<t_Coordinate> f_GetPositions();
    int f_GetNumNodes();
};


#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H
