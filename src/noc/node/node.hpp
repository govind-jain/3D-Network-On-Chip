#ifndef INC_3D_NETWORK_ON_CHIP_NODE_HPP
#define INC_3D_NETWORK_ON_CHIP_NODE_HPP

#include "../types/types.hpp"
#include <bits/stdc++.h>
using namespace std;

#define t_Neighbours vector<c_Node*>

class c_Node {
private:
    t_NodeType m_Type;
    t_SwitchId m_SwitchId;
    t_Coordinates m_Coordinates;
    t_RepeaterId m_RepeaterId;
    t_Axis m_Axis;
    t_Neighbours m_Neighbours;
public:
    c_Node(t_SwitchId p_SwitchId);
    c_Node(t_RepeaterId p_RepeaterId);
    void f_SetCoordinates(t_Coordinates p_Coordinates);
    void f_SetAxis(t_Axis p_Axis);
    void f_SetNeighbour(t_DirectionIndex p_DirectionIndex, c_Node* p_Neighbour);
    t_NodeType f_GetNodeType() const;
    t_Coordinates f_GetCoordinates();
};

#endif //INC_3D_NETWORK_ON_CHIP_NODE_HPP
