#include "node.hpp"

c_Node::c_Node(t_SwitchId p_SwitchId) {
    this->m_SwitchId = p_SwitchId;
    this->m_Type = E_Type_Switch;
    m_Neighbours.resize(E_Switch_Size,nullptr);
}

c_Node::c_Node(t_RepeaterId p_RepeaterId) {
    this->m_RepeaterId = p_RepeaterId;
    this->m_Type = E_Type_Repeater;
    m_Neighbours.resize(E_Repeater_Size,nullptr);
}

void c_Node::f_SetCoordinates(t_Coordinates p_Coordinates){
    this->m_Coordinates = p_Coordinates;
}

void c_Node::f_SetAxis(t_Axis p_Axis) {
    this->m_Axis = p_Axis;
}

void c_Node::f_SetNeighbour(t_DirectionIndex p_DirectionIndex, c_Node *p_Neighbour) {
    m_Neighbours[p_DirectionIndex] = p_Neighbour;
}

t_NodeType c_Node::f_GetNodeType() const {
    return this->m_Type;
}

t_Coordinates c_Node::f_GetCoordinates() {
    return this->m_Coordinates;
}

t_SwitchId c_Node::f_GetSwitchId(){
    return this->m_SwitchId;
}

t_RepeaterId c_Node::f_GetRepeaterId(){
    return this->m_RepeaterId;
}

c_Node* c_Node::f_GetNeighbour(t_DirectionIndex p_DirectionIndex){
    return this->m_Neighbours[p_DirectionIndex];
}
