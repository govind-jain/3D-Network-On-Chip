#ifndef INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H
#define INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H

#include "../types/types.h"

class TopologyConfig{
private:
    int m_NumNodes;
    vector<t_Coordinate> m_Position;
    t_Neighbours m_Neighbours;
public:
    void f_SetTopology();

};


#endif //INC_3D_NETWORK_ON_CHIP_TOPOLOGYCONFIG_H
