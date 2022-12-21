#include "RoutingTable.hpp"

//t_DirectionIndex c_RoutingTable::f_GetNextRoutingStep(t_RepeaterId p_SrcRepeaterId, t_SwitchId p_DestSwitchId){
//    return this->m_RepeaterRoutingTable[p_DestSwitchId][p_SrcRepeaterId];
//    return this->m_RepeaterRoutingTable[p_SrcRepeaterId][p_DestSwitchId];
//}

t_DirectionIndex c_RoutingTable::f_GetNextRoutingStep(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId){
    return this->m_SwitchRoutingTable[p_SrcSwitchId][p_DestSwitchId];
}