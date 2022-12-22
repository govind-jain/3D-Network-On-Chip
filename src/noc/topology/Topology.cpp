#include "Topology.hpp"

void c_Topology::f_SetNumberOfSwitches(int p_NumberOfSwitches){
    this->m_NumberOfSwitches = p_NumberOfSwitches;
}

void c_Topology::f_SetAdjacencyList(t_AdjacencyList p_AdjacencyList) {
    this->m_AdjacencyList = p_AdjacencyList;
}

void c_Topology::f_SetListOfSwitchPointers() {

    this->m_ListOfSwitchPointers.resize(this->m_NumberOfSwitches);

    for (int l_Counter = 0; l_Counter < this->m_NumberOfSwitches; ++l_Counter) {
        this->m_ListOfSwitchPointers[l_Counter] = new c_Node(l_Counter);
    }
}

void c_Topology::f_SetCoordinatesOfSwitches(vector<t_Coordinates> p_CoordinatesList){
    for (int l_Counter = 0; l_Counter < this->m_NumberOfSwitches; ++l_Counter) {
        this->m_ListOfSwitchPointers[l_Counter]->f_SetCoordinates(p_CoordinatesList[l_Counter]);
    }
}

t_Axis c_Topology::f_GetAxisOfDifferenceOfSwitches(t_SwitchId p_SwitchId1, t_SwitchId p_SwitchId2) {

    t_Coordinates l_CoordinatesSwitch1 = this->m_ListOfSwitchPointers[p_SwitchId1]->f_GetCoordinates();
    t_Coordinates l_CoordinatesSwitch2 = this->m_ListOfSwitchPointers[p_SwitchId2]->f_GetCoordinates();

    if (get<0>(l_CoordinatesSwitch1) != get<0>(l_CoordinatesSwitch2)) {
        return E_XAxis;
    }
    else if (get<1>(l_CoordinatesSwitch1) != get<1>(l_CoordinatesSwitch2)) {
        return E_YAxis;
    }
    else{
        return E_ZAxis;
    }
}

void c_Topology::f_SetConnections(){

    for (t_SwitchId l_SrcSwitchId = 0; l_SrcSwitchId < this->m_NumberOfSwitches; ++l_SrcSwitchId) {
        for (auto l_NeighbourOfSrcSwitch: this->m_AdjacencyList[l_SrcSwitchId]) {

            t_SwitchId l_DestSwitchId = l_NeighbourOfSrcSwitch.first;
            int l_NumberOfIntermediateRepeaters = l_NeighbourOfSrcSwitch.second;
            t_Axis l_AxisOfDifference = this->f_GetAxisOfDifferenceOfSwitches(l_SrcSwitchId, l_DestSwitchId);

            cout << "(Debug) " << l_SrcSwitchId << " " << l_DestSwitchId << endl;

            c_Node *o_PrevNode = m_ListOfSwitchPointers[l_SrcSwitchId];

            for (int l_RepeaterCounter = 0; l_RepeaterCounter < l_NumberOfIntermediateRepeaters; ++l_RepeaterCounter) {

                t_RepeaterId m_RepeaterId = {l_SrcSwitchId, l_DestSwitchId, l_RepeaterCounter};
                c_Node *o_Repeater = new c_Node(m_RepeaterId);

                o_Repeater->f_SetAxis(l_AxisOfDifference);
                o_Repeater->f_SetNeighbour(E_Prev, o_PrevNode);

                if (o_PrevNode->f_GetNodeType() == E_Type_Switch) {
                    o_PrevNode->f_SetNeighbour(l_AxisOfDifference * 2, o_Repeater);
                }
                else {
                    o_PrevNode->f_SetNeighbour(E_Next, o_Repeater);
                }

                o_PrevNode = o_Repeater;
            }

            if (o_PrevNode->f_GetNodeType() == E_Type_Switch) {
                o_PrevNode->f_SetNeighbour(l_AxisOfDifference * 2, m_ListOfSwitchPointers[l_DestSwitchId]);
            }
            else {
                o_PrevNode->f_SetNeighbour(E_Next, m_ListOfSwitchPointers[l_DestSwitchId]);
            }

            m_ListOfSwitchPointers[l_DestSwitchId]->f_SetNeighbour(l_AxisOfDifference * 2 + 1, o_PrevNode);
        }
    }
}

c_Topology::c_Topology(c_TopologyConfig *p_TopologyConfig) {

    f_SetNumberOfSwitches(p_TopologyConfig->f_GetNumberOfNodes());
    f_SetAdjacencyList(p_TopologyConfig->f_GetAdjacencyList());
    f_SetListOfSwitchPointers();
    f_SetCoordinatesOfSwitches(p_TopologyConfig->f_GetCoordinatesList());
    f_SetConnections();

    cout << "(Debug) " << "Object Created Successfully\n";
}

c_Node* c_Topology::f_GetSwitchPointer(t_SwitchId p_SwitchId){
    return this->m_ListOfSwitchPointers[p_SwitchId];
}

int c_Topology::f_GetNumberOfSwitches(){
    return this->m_NumberOfSwitches;
}

t_AdjacencyListOfSwitch c_Topology::f_AdjacencyListOfSwitch(t_SwitchId p_SwitchId){
    return this->m_AdjacencyList[p_SwitchId];
}
