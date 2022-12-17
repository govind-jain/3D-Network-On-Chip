#include "Topology.h"

// Need to replace vector<c_Node *> with a type variable
void c_Topology::SetAddress(vector<c_Node *> p_Address) {
    m_Address.resize(p_Address.size());
    for (int i = 0; i < p_Address.size(); ++i) {
        m_Address[i] = p_Address[i];
    }
}

void c_Topology::SetPosition(vector<t_Coordinate> p_Position) {
    m_Position.resize(p_Position.size());
    for (int i = 0; i < p_Position.size(); ++i) {
        m_Position[i] = p_Position[i];
    }
}

t_AxisType c_Topology::f_GetAxis(int &i, int &j) {
    if (get<0>(this->m_Position[i]) != get<0>(this->m_Position[j])) {
        return E_XAxis;
    } else if (get<1>(this->m_Position[i]) != get<1>(this->m_Position[j])) {
        return E_YAxis;
    } else {
        return E_ZAxis;
    }
}

c_Topology::c_Topology(TopologyConfig *T) {

    // Upcoming lines until setAddress() may be directly covered in the
    // setAddress() by passing the T->f_GetNumNodes()

    this->m_NumNodes = T->f_GetNumNodes();

    vector<c_Node *> l_Address(m_NumNodes);
    for (int i = 0; i < m_NumNodes; ++i) {
        c_Node *l_Node = new c_Node(i);
        l_Address[i] = l_Node;
    }

    SetAddress(l_Address);

    SetPosition(T->f_GetPositions());

    t_AdjacencyList l_AdjacencyList = T->f_GetNeighbours();

    // Is it fine to use l_AdjacencyList.size() and l_AdjacencyList[i].size()?
    for (int i = 0; i < l_AdjacencyList.size(); ++i) {
        for (int j = 0; j < l_AdjacencyList[i].size(); ++j) {
            int l_SrcSwitch = i;
            int l_DestSwitch = l_AdjacencyList[i][j].first;
            int l_NumRepeaters = l_AdjacencyList[i][j].second;
            int l_Axis = this->f_GetAxis(l_SrcSwitch, l_DestSwitch);
            cout << "(Debug) " << l_SrcSwitch << " " << l_DestSwitch << endl;

            c_Node *o_PrevNode = m_Address[l_SrcSwitch];

            // In case l_NumRepeaters is 0 then it may not make connection src->dest
            // We may use a separate function to a create the links of repeaters
            for (int k = 0; k < l_NumRepeaters; ++k) {
                t_RepeaterId m_RepeaterId = {l_SrcSwitch, l_DestSwitch, k};
                c_Node *o_Repeater = new c_Node(m_RepeaterId);
                o_Repeater->f_SetAxis(l_Axis);
                o_Repeater->f_SetNeighbour(E_Prev, o_PrevNode);
                if (o_PrevNode->f_GetType() == E_Type_Switch) {
                    o_PrevNode->f_SetNeighbour(l_Axis * 2, o_Repeater);
                } else {
                    o_PrevNode->f_SetNeighbour(E_Next, o_Repeater);
                }
                o_PrevNode = o_Repeater;
            }
            if (o_PrevNode->f_GetType() == E_Type_Switch) {
                o_PrevNode->f_SetNeighbour(l_Axis * 2, m_Address[l_DestSwitch]);
            } else {
                o_PrevNode->f_SetNeighbour(E_Next, m_Address[l_DestSwitch]);
            }
            m_Address[l_DestSwitch]->f_SetNeighbour(l_Axis * 2 + 1, o_PrevNode);
        }
    }
    cout << "(Debug) " << "Object Created Successfully\n";
}

