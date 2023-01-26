#ifndef INC_3D_NETWORK_ON_CHIP_ROUTING_H
#define INC_3D_NETWORK_ON_CHIP_ROUTING_H

#include "../types/types.hpp"
#include "../node/node.hpp"
#include "../topology/Topology.hpp"
#include "../topology/TopologyConfig.hpp"
using namespace std;

class c_Routing {
    protected:
        t_RoutingAlgo m_RoutingAlgo;
        c_Topology *m_Topology;
        t_RoutingTable m_RoutingTable;

    public:
        c_Routing(c_TopologyConfig *p_TopologyConfig);
        c_Routing(c_Topology *p_Topology);
        t_DirectionIndex f_GetRoute(c_Node* p_CurrSwitch, t_SwitchId p_DestSwitchId);
        void f_GetRoutingPath(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId);
//    t_DirectionIndex f_GetRoute(t_SwitchId p_CurrSwitchId, t_SwitchId p_DestSwitchId);
};

#endif //INC_3D_NETWORK_ON_CHIP_ROUTING_H
