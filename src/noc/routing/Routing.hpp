#ifndef INC_3D_NETWORK_ON_CHIP_ROUTING_H
#define INC_3D_NETWORK_ON_CHIP_ROUTING_H

#include "../types/types.hpp"
#include "../topology/TopologyConfig.hpp"
#include "ShortestPathRouting.hpp"
#include <bits/stdc++.h>
using namespace std;

class c_Routing : virtual public c_ShortestPathRouting{
    private:
        t_RoutingAlgo m_RoutingAlgo;

    public:
        c_Routing(t_RoutingAlgo p_RoutingAlgo, c_TopologyConfig *T);
        void f_GetRoutingPath(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId);
};

#endif //INC_3D_NETWORK_ON_CHIP_ROUTING_H
