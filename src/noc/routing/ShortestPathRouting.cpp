#include "ShortestPathRouting.hpp"

t_AdjacencyMatrix f_GetAllPairsShortestPath(int p_NumberOfSwitches, t_AdjacencyMatrix p_WeightedAdjacencyMatrix) {

    for (t_SwitchId l_IntermediateSwitchId = 0; l_IntermediateSwitchId < p_NumberOfSwitches; ++l_IntermediateSwitchId) {
        for (t_SwitchId l_SrcSwitchId = 0; l_SrcSwitchId < p_NumberOfSwitches; ++l_SrcSwitchId) {
            for (t_SwitchId l_DestSwitchId = 0; l_DestSwitchId < p_NumberOfSwitches; ++l_DestSwitchId) {
                p_WeightedAdjacencyMatrix[l_SrcSwitchId][l_DestSwitchId] =
                        min(p_WeightedAdjacencyMatrix[l_SrcSwitchId][l_DestSwitchId],
                            p_WeightedAdjacencyMatrix[l_SrcSwitchId][l_IntermediateSwitchId] +
                            p_WeightedAdjacencyMatrix[l_IntermediateSwitchId][l_DestSwitchId]);
            }
        }
    }

    return p_WeightedAdjacencyMatrix;
}

t_Distance c_ShortestPathRouting::f_FindDistanceBetweenSwitches(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2){

    t_Coordinates l_CoordinatesSwitch1 = this->m_Topology->f_GetSwitchPointer(p_SwitchId1)->f_GetCoordinates();
    t_Coordinates l_CoordinatesSwitch2 = this->m_Topology->f_GetSwitchPointer(p_SwitchId2)->f_GetCoordinates();

    t_Distance l_XDist = get<0>(l_CoordinatesSwitch1) - get<0>(l_CoordinatesSwitch2);
    t_Distance l_YDist = get<1>(l_CoordinatesSwitch1) - get<1>(l_CoordinatesSwitch2);
    t_Distance l_ZDist = get<2>(l_CoordinatesSwitch1) - get<2>(l_CoordinatesSwitch2);

    return sqrt(pow(l_XDist, 2) + pow(l_YDist, 2) + pow(l_ZDist, 2));
}

t_DirectionIndex c_ShortestPathRouting::f_GetDirectionOfNeighbour(t_SwitchId p_SrcSwitch, t_SwitchId p_DestSwitch) {

    t_Coordinates l_CoordinatesOfSrcSwitch = this->m_Topology->f_GetSwitchPointer(p_SrcSwitch)->f_GetCoordinates();
    t_Coordinates l_CoordinatesOfDestSwitch = this->m_Topology->f_GetSwitchPointer(p_DestSwitch)->f_GetCoordinates();

    if (get<0>(l_CoordinatesOfSrcSwitch) != get<0>(l_CoordinatesOfDestSwitch)) {
        if(get<0>(l_CoordinatesOfSrcSwitch) < get<0>(l_CoordinatesOfDestSwitch)){
            return E_East;
        }
        else{
            return E_West;
        }
    }
    else if (get<1>(l_CoordinatesOfSrcSwitch) != get<1>(l_CoordinatesOfDestSwitch)) {
        if(get<1>(l_CoordinatesOfSrcSwitch) < get<1>(l_CoordinatesOfDestSwitch)){
            return E_North;
        }
        else{
            return E_South;
        }
    }
    else{
        if(get<2>(l_CoordinatesOfSrcSwitch) < get<2>(l_CoordinatesOfDestSwitch)){
            return E_Up;
        }
        else{
            return E_Down;
        }
    }

    return E_NotDefined;
}

void c_ShortestPathRouting::f_SetDistanceAdjacencyMatrix(){

    int l_NumberOfSwitches = this->m_Topology->f_GetNumberOfSwitches();

    this->m_DistanceAdjacencyMatrix.resize(l_NumberOfSwitches, vector<t_Distance>(l_NumberOfSwitches, INF));

    for (t_SwitchId l_SrcSwitchId = 0; l_SrcSwitchId < l_NumberOfSwitches; ++l_SrcSwitchId) {

        this->m_DistanceAdjacencyMatrix[l_SrcSwitchId][l_SrcSwitchId] = 0;

        t_AdjacencyListOfSwitch l_AdjacencyListOfSrcSwitch = this->m_Topology->f_GetAdjacencyListOfSwitch(l_SrcSwitchId);

        for (auto &l_NeighbourOfSrcSwitch: l_AdjacencyListOfSrcSwitch) {
            t_SwitchId l_DestSwitchId = l_NeighbourOfSrcSwitch.first;
            t_Distance l_DistanceBetweenSrcAndDest = f_FindDistanceBetweenSwitches(l_SrcSwitchId, l_DestSwitchId);
            this->m_DistanceAdjacencyMatrix[l_SrcSwitchId][l_DestSwitchId] = l_DistanceBetweenSrcAndDest;
            this->m_DistanceAdjacencyMatrix[l_DestSwitchId][l_SrcSwitchId] = l_DistanceBetweenSrcAndDest;
        }
    }
}

void c_ShortestPathRouting::f_SetRoutingTable(t_AdjacencyMatrix p_WeightedAdjacencyMatrix){

    int l_NumberOfSwitches = this->m_Topology->f_GetNumberOfSwitches();

    this->m_RoutingTable.resize(l_NumberOfSwitches, vector<t_DirectionIndex>(l_NumberOfSwitches, E_NotDefined));

    t_AdjacencyMatrix l_AllPairsShortestPath = f_GetAllPairsShortestPath(l_NumberOfSwitches, p_WeightedAdjacencyMatrix);

    for (t_SwitchId l_NeighbourOneSwitch = 0; l_NeighbourOneSwitch < l_NumberOfSwitches; ++l_NeighbourOneSwitch) {

        t_AdjacencyListOfSwitch l_AdjacencyListOfNeighborOneSwitch = this->m_Topology->f_GetAdjacencyListOfSwitch(l_NeighbourOneSwitch);

        for (auto &l_NeighbouringSwitchOfOne: l_AdjacencyListOfNeighborOneSwitch) {

            t_SwitchId l_NeighbourTwoSwitch = l_NeighbouringSwitchOfOne.first;

            for(t_SwitchId l_DestSwitch = 0; l_DestSwitch < l_NumberOfSwitches; l_DestSwitch++){

                t_Distance l_ShortestPathFromNeighbourOneToDest = l_AllPairsShortestPath[l_NeighbourOneSwitch][l_DestSwitch];
                t_Distance l_ShortestPathFromNeighbourTwoToDest = l_AllPairsShortestPath[l_NeighbourTwoSwitch][l_DestSwitch];
                t_Distance l_DistanceBetweenOneAndTwo = this->m_DistanceAdjacencyMatrix[l_NeighbourOneSwitch][l_NeighbourTwoSwitch];

                if(l_ShortestPathFromNeighbourOneToDest == l_DistanceBetweenOneAndTwo + l_ShortestPathFromNeighbourTwoToDest){
                    t_DirectionIndex l_DirectionIndexFromOneToTwo = this->f_GetDirectionOfNeighbour(l_NeighbourOneSwitch, l_NeighbourTwoSwitch);
                    this->m_RoutingTable[l_NeighbourOneSwitch][l_DestSwitch] = l_DirectionIndexFromOneToTwo;
                }

                if(l_DistanceBetweenOneAndTwo + l_ShortestPathFromNeighbourOneToDest == l_ShortestPathFromNeighbourTwoToDest){
                    t_DirectionIndex l_DirectionIndexFromTwoToOne = this->f_GetDirectionOfNeighbour(l_NeighbourTwoSwitch, l_NeighbourOneSwitch);
                    this->m_RoutingTable[l_NeighbourTwoSwitch][l_DestSwitch] = l_DirectionIndexFromTwoToOne;
                }
            }
        }
    }
}

c_ShortestPathRouting::c_ShortestPathRouting(c_TopologyConfig *p_TopologyConfig) : c_Routing(p_TopologyConfig) {
    this->m_RoutingAlgo = E_ShortestPathRouting;
    this->f_SetDistanceAdjacencyMatrix();
    this->f_SetRoutingTable(this->m_DistanceAdjacencyMatrix);
}