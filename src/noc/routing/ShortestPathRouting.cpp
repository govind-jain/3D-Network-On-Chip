#include "ShortestPathRouting.hpp"

t_Distance c_ShortestPathRouting::f_FindDistanceBetweenSwitches(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2){

    t_Coordinates l_CoordinatesSwitch1 = this->m_ListOfNodePointers[p_SwitchId1]->f_GetCoordinates();
    t_Coordinates l_CoordinatesSwitch2 = this->m_ListOfNodePointers[p_SwitchId2]->f_GetCoordinates();

    t_Distance l_XDist = get<0>(l_CoordinatesSwitch1) - get<0>(l_CoordinatesSwitch2);
    t_Distance l_YDist = get<1>(l_CoordinatesSwitch1) - get<1>(l_CoordinatesSwitch2);
    t_Distance l_ZDist = get<2>(l_CoordinatesSwitch1) - get<2>(l_CoordinatesSwitch2);

    return sqrt(pow(l_XDist, 2) + pow(l_YDist, 2) + pow(l_ZDist, 2));
}

void c_ShortestPathRouting::f_SetAdjacencyMatrix(){

    this->m_AdjacencyMatrix.resize(this->m_NumberOfNodes, vector<t_Distance>(this->m_NumberOfNodes, INF));

    for (t_SwitchId l_SrcSwitchId = 0; l_SrcSwitchId < this->m_NumberOfNodes; ++l_SrcSwitchId) {
        for (auto l_NeighbourOfSrcSwitch: this->m_AdjacencyList[l_SrcSwitchId]) {
            t_SwitchId l_DestSwitchId = l_NeighbourOfSrcSwitch.first;
            t_Distance l_DistanceBetweenSrcAndDest = f_FindDistanceBetweenSwitches(l_SrcSwitchId, l_DestSwitchId);
            this->m_AdjacencyMatrix[l_SrcSwitchId][l_DestSwitchId] = l_DistanceBetweenSrcAndDest;
            this->m_AdjacencyMatrix[l_DestSwitchId][l_SrcSwitchId] = l_DistanceBetweenSrcAndDest;
        }
    }
}

t_AdjacencyMatrix c_ShortestPathRouting::f_GetAllPairsShortestPath() {

    t_AdjacencyMatrix l_AllPairsShortestPath = this->m_AdjacencyMatrix;

    for (t_SwitchId l_IntermediateSwitchId = 0; l_IntermediateSwitchId < this->m_NumberOfNodes; ++l_IntermediateSwitchId) {
        for (t_SwitchId l_SrcSwitchId = 0; l_SrcSwitchId < this->m_NumberOfNodes; ++l_SrcSwitchId) {
            for (t_SwitchId l_DestSwitchId = 0; l_DestSwitchId < this->m_NumberOfNodes; ++l_DestSwitchId) {
                l_AllPairsShortestPath[l_SrcSwitchId][l_DestSwitchId] = min(l_AllPairsShortestPath[l_SrcSwitchId][l_DestSwitchId],
                                                   l_AllPairsShortestPath[l_SrcSwitchId][l_IntermediateSwitchId] + l_AllPairsShortestPath[l_IntermediateSwitchId][l_DestSwitchId]);
            }
        }
    }

    return l_AllPairsShortestPath;
}