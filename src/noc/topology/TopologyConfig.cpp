#include "TopologyConfig.hpp"

void f_SwapIdsFromLowToHigh(t_SwitchId &p_SwitchId1, t_SwitchId &p_SwitchId2, t_CoordinatesList &p_CoordinatesListOfSwitches) {
    if (get<0>(p_CoordinatesListOfSwitches[p_SwitchId1]) != get<0>(p_CoordinatesListOfSwitches[p_SwitchId2])) {
        if (get<0>(p_CoordinatesListOfSwitches[p_SwitchId1]) > get<0>(p_CoordinatesListOfSwitches[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
    else if (get<1>(p_CoordinatesListOfSwitches[p_SwitchId1]) != get<1>(p_CoordinatesListOfSwitches[p_SwitchId2])) {
        if (get<1>(p_CoordinatesListOfSwitches[p_SwitchId1]) > get<1>(p_CoordinatesListOfSwitches[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
    else {
        if (get<2>(p_CoordinatesListOfSwitches[p_SwitchId1]) > get<2>(p_CoordinatesListOfSwitches[p_SwitchId2])) {
            swap(p_SwitchId1, p_SwitchId2);
        }
    }
}

tuple<int, t_CoordinatesList, t_AdjacencyListOfSwitches> f_InputReader() {

    int l_NumberOfSwitches, l_NumberOfConnections;
    cin >> l_NumberOfSwitches >> l_NumberOfConnections;

    t_CoordinatesList l_CoordinatesListOfSwitches(l_NumberOfSwitches);
    t_AdjacencyListOfSwitches l_AdjacencyListOfSwitches(l_NumberOfSwitches);

    for (int l_Counter = 0; l_Counter < l_NumberOfSwitches; ++l_Counter) {
        t_Coordinate l_xC, l_yC, l_zC;
        t_SwitchId l_SwitchId;
        cin >> l_xC >> l_yC >> l_zC >> l_SwitchId;
        l_CoordinatesListOfSwitches[l_SwitchId] = {l_xC, l_yC, l_zC};
    }

    for (int l_Counter = 0; l_Counter < l_NumberOfConnections; ++l_Counter) {
        t_SwitchId l_SwitchId1, l_SwitchId2;
        int l_NumberOfIntermediateRepeaters;
        cin >> l_SwitchId1 >> l_SwitchId2 >> l_NumberOfIntermediateRepeaters;

//        How to swap if one coordinate high & one low
        f_SwapIdsFromLowToHigh(l_SwitchId1,l_SwitchId2,l_CoordinatesListOfSwitches);
        l_AdjacencyListOfSwitches[l_SwitchId1].push_back({l_SwitchId2, l_NumberOfIntermediateRepeaters});
    }

    return make_tuple(l_NumberOfSwitches, l_CoordinatesListOfSwitches, l_AdjacencyListOfSwitches);
}

void c_TopologyConfig::f_SetTopologyFromInput() {

    tuple<int, t_CoordinatesList, t_AdjacencyListOfSwitches> l_InputReadings = f_InputReader();

    this->m_NumberOfSwitches = get<0>(l_InputReadings);
    this->m_CoordinatesListOfSwitches = get<1>(l_InputReadings);
    this->m_AdjacencyListOfSwitches = get<2>(l_InputReadings);

}

t_AdjacencyListOfSwitches c_TopologyConfig::f_GetAdjacencyListOfSwitches() {
    return this->m_AdjacencyListOfSwitches;
}

t_CoordinatesList c_TopologyConfig::f_GetCoordinatesListOfSwitches() {
    return this->m_CoordinatesListOfSwitches;
}

int c_TopologyConfig::f_GetNumberOfSwitches() {
    return this->m_NumberOfSwitches;
}