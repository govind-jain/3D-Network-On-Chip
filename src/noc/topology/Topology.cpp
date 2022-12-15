#include "Topology.h"

c_Topology::c_Topology(int p_NumNodes) {
    this->l_NumNodes = p_NumNodes;
    l_Address.resize(p_NumNodes);
}

void c_Topology::SetAddress(vector<c_Node *> p_Address) {
    for (int i = 0; i < p_Address.size(); ++i) {
        l_Address[i] = p_Address[i];
    }
}

void c_Topology::SetPosition(vector<t_Coordinate> p_Position) {
    for (int i = 0; i < p_Position.size(); ++i) {
        l_Position[i] = p_Position[i];
    }
}

c_Topology::c_Topology(TopologyConfig *T) {
    cout <<"(Debug)"<< " New Topology Created\n";
    //TODO
}

