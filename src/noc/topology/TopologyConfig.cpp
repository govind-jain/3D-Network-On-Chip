#include "TopologyConfig.hpp"

void f_Swap(t_SwitchId &p_SwitchId1, t_SwitchId &p_SwitchId2, vector<t_Coordinates> &p_CoordinatesList) {
    if (get<0>(p_CoordinatesList[p_SwitchId1]) != get<0>(p_CoordinatesList[p_SwitchId2])) {
        if (get<0>(p_CoordinatesList[p_SwitchId1]) > get<0>(p_CoordinatesList[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
    else if (get<1>(p_CoordinatesList[p_SwitchId1]) != get<1>(p_CoordinatesList[p_SwitchId2])) {
        if (get<1>(p_CoordinatesList[p_SwitchId1]) > get<1>(p_CoordinatesList[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
    else {
        if (get<2>(p_CoordinatesList[p_SwitchId1]) > get<2>(p_CoordinatesList[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
}

tuple<int, vector<t_Coordinates>, t_AdjacencyList> f_Reader() {

    int l_NumberOfNodes, l_NumberOfConnections;
    cin >> l_NumberOfNodes >> l_NumberOfConnections;

    vector<t_Coordinates> l_CoordinatesList(l_NumberOfNodes);
    t_AdjacencyList l_AdjacencyList(l_NumberOfNodes);

    for (int l_Counter = 0; l_Counter < l_NumberOfNodes; ++l_Counter) {
        t_Coordinate l_xC, l_yC, l_zC;
        t_SwitchId l_SwitchId;
        cin >> l_xC >> l_yC >> l_zC >> l_SwitchId;
        t_Coordinates l_Coordinates = {l_xC, l_yC, l_zC};
        l_CoordinatesList[l_SwitchId] = l_Coordinates;
    }

    for (int l_Counter = 0; l_Counter < l_NumberOfConnections; ++l_Counter) {
        t_SwitchId l_SwitchId1, l_SwitchId2;
        int l_NumberOfIntermediateRepeaters;
        cin >> l_SwitchId1 >> l_SwitchId2 >> l_NumberOfIntermediateRepeaters;
        f_Swap(l_SwitchId1,l_SwitchId2,l_CoordinatesList);
        l_AdjacencyList[l_SwitchId1].push_back({l_SwitchId2, l_NumberOfIntermediateRepeaters});
    }

    return make_tuple(l_NumberOfNodes, l_CoordinatesList, l_AdjacencyList);
}

void TopologyConfig::f_SetTopologyFromInput() {

    tuple<int, vector<t_Coordinates>, t_AdjacencyList> l_InputReadings = f_Reader();

    m_NumberOfNodes = get<0>(l_InputReadings);
    m_CoordinatesList = get<1>(l_InputReadings);
    m_AdjacencyList = get<2>(l_InputReadings);

    cout << "(Debug)" << m_NumberOfNodes << endl;
}

t_AdjacencyList TopologyConfig::f_GetAdjacencyList() {
    return m_AdjacencyList;
}

vector<t_Coordinates> TopologyConfig::f_GetCoordinatesList() {
    return m_CoordinatesList;
}

int TopologyConfig::f_GetNumberOfNodes() {
    return m_NumberOfNodes;
}