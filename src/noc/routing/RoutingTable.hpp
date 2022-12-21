#ifndef INC_3D_NETWORK_ON_CHIP_ROUTING_TABLE_H
#define INC_3D_NETWORK_ON_CHIP_ROUTING_TABLE_H

#include "../types/types.hpp"
#include <bits/stdc++.h>

using namespace std;

class c_RoutingTable {
    protected:
        t_SwitchRoutingTable m_SwitchRoutingTable;
//        t_RepeaterRoutingTable m_RepeaterRoutingTable;
    public:
//        t_DirectionIndex f_GetNextRoutingStep(t_RepeaterId p_SrcRepeaterId, t_SwitchId p_DestSwitchId);
        t_DirectionIndex f_GetNextRoutingStep(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId);
};

#endif //INC_3D_NETWORK_ON_CHIP_ROUTING_TABLE_H
