#include "Routing.hpp"
using namespace std;

c_Routing::c_Routing(t_RoutingAlgo p_RoutingAlgo, c_TopologyConfig *p_TopologyConfig) {
    if (p_RoutingAlgo == E_ShortestPathRouting) {
        this->m_RoutingAlgo = E_ShortestPathRouting;
        this->f_SetTopology(p_TopologyConfig);
        this->f_SetRoutingTables();
    }
}

void inline f_PrintRepeaterId(t_RepeaterId p_RepeaterId){
    cout << "Repeater: " << get<0>(p_RepeaterId) << " " << get<1>(p_RepeaterId) << " " << get<2>(p_RepeaterId) << endl;
}

void c_Routing::f_GetRoutingPath(t_SwitchId p_SrcSwitchId, t_SwitchId p_DestSwitchId){

    while(p_SrcSwitchId != p_DestSwitchId){

        t_DirectionIndex l_NextStepForSwitch = m_SwitchRoutingTable[p_SrcSwitchId][p_DestSwitchId];
        t_DirectionIndex l_NextStepForRepeater = (l_NextStepForSwitch%2 == 0)?E_Next:E_Prev;

        c_Node *l_TempNode = this->m_ListOfNodePointers[p_SrcSwitchId];

        cout << "Switch:" << (l_TempNode->f_GetSwitchId()) << endl;
        l_TempNode = l_TempNode->f_GetNeighbour(l_NextStepForSwitch);

        while(l_TempNode->f_GetNodeType() != E_Type_Switch){
            f_PrintRepeaterId(l_TempNode->f_GetRepeaterId());
            l_TempNode = l_TempNode->f_GetNeighbour(l_NextStepForRepeater);
        }

        p_SrcSwitchId = l_TempNode->f_GetSwitchId();
    }

    cout << "Switch:" << (p_DestSwitchId) << endl;
}
