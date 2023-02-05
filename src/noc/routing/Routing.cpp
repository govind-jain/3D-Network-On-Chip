#include "Routing.hpp"
using namespace std;

c_Routing::c_Routing(c_TopologyConfig *p_TopologyConfig) {
//    cout << "(Debug): Called constructor for c_Topology" << endl;
    this->m_Topology = new c_Topology(p_TopologyConfig);
//    cout << "(Debug): Completed calling constructor for c_Topology" << endl;
}

c_Routing::c_Routing(c_Topology *p_Topology) {
    this->m_Topology = p_Topology;
}

void inline f_PrintRepeaterDetails(t_RepeaterId p_RepeaterId){
    cout << "Curr Repeater: " << get<0>(p_RepeaterId) << " " << get<1>(p_RepeaterId) << " " << get<2>(p_RepeaterId) << endl;
}

t_DirectionIndex c_Routing::f_GetRoute(c_Node* p_CurrSwitch, t_SwitchId p_DestSwitchId){
    t_SwitchId l_CurrSwitchId = p_CurrSwitch->f_GetSwitchId();
    return this->m_RoutingTable[l_CurrSwitchId][p_DestSwitchId];
}

void c_Routing::f_GetRoutingPath(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId){

    cout << "-----------------------" << endl;

    c_Node* l_CurrSwitch = this->m_Topology->f_GetSwitchPointer(p_SrcSwitchId);
    c_Node* l_CurrNode;

    while(l_CurrSwitch->f_GetSwitchId() != p_DestSwitchId){

        t_DirectionIndex l_NextStepForSwitch = this->f_GetRoute(l_CurrSwitch, p_DestSwitchId);
        t_DirectionIndex l_NextStepForRepeater = (l_NextStepForSwitch%2 == 0)?E_Next:E_Prev;

        cout << "Curr Switch:" << (l_CurrSwitch->f_GetSwitchId()) << endl;

        l_CurrNode = l_CurrSwitch->f_GetNeighbour(l_NextStepForSwitch);

        while(l_CurrNode->f_GetNodeType() == E_Type_Repeater){
            f_PrintRepeaterDetails(l_CurrNode->f_GetRepeaterId());
            l_CurrNode = l_CurrNode->f_GetNeighbour(l_NextStepForRepeater);
        }

        l_CurrSwitch = l_CurrNode;
    }

    cout << "Dest Switch:" << (l_CurrSwitch->f_GetSwitchId()) << endl;
}

//t_DirectionIndex c_Routing::f_GetRoute(t_SwitchId p_CurrSwitchId, t_SwitchId p_DestSwitchId){
//    return this->m_RoutingTable[p_CurrSwitchId][p_DestSwitchId];
//}
//
//void c_Routing::f_GetRoutingPath(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId){
//
//    t_SwitchId l_CurrSwitchId = p_SrcSwitchId;
//
//    cout << "-----------------------" << endl;
//
//    while(l_CurrSwitchId != p_DestSwitchId){
//
//        t_DirectionIndex l_NextStepForSwitch = this->f_GetRoute(l_CurrSwitchId, p_DestSwitchId);
//        t_DirectionIndex l_NextStepForRepeater = (l_NextStepForSwitch%2 == 0)?E_Next:E_Prev;
//
//        c_Node *l_TempNode = this->m_Topology->f_GetSwitchPointer(l_CurrSwitchId);
//
//        cout << "Curr Switch:" << (l_TempNode->f_GetSwitchId()) << endl;
//        l_TempNode = l_TempNode->f_GetNeighbour(l_NextStepForSwitch);
//
//        while(l_TempNode->f_GetNodeType() != E_Type_Switch){
//            f_PrintRepeaterId(l_TempNode->f_GetRepeaterId());
//            l_TempNode = l_TempNode->f_GetNeighbour(l_NextStepForRepeater);
//        }
//
//        l_CurrSwitchId = l_TempNode->f_GetSwitchId();
//    }
//
//    cout << "Dest Switch:" << (l_CurrSwitchId) << endl;
//}
