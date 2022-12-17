#include "node.h"

c_Node::c_Node(int id) {
    this->m_SwitchId = id;
    this->m_Type = E_Type_Switch;
    m_Neighbours.resize(E_Switch_Size,nullptr);
}

c_Node::c_Node(t_RepeaterId id) {
    this->m_RepeaterId = id;
    this->m_Type = E_Type_Repeater;
    m_Neighbours.resize(E_Repeater_Size,nullptr);
}

void c_Node::f_SetAxis(t_Axis p_Axis) {
    this->m_Axis = p_Axis;
}

void c_Node::f_SetNeighbour(int p_Index, c_Node *p_Neighbour) {
    m_Neighbours[p_Index] = p_Neighbour;
}

int c_Node::f_GetType() const {
    return m_Type;
}
