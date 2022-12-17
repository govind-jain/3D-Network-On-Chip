#ifndef INC_3D_NETWORK_ON_CHIP_NODE_H
#define INC_3D_NETWORK_ON_CHIP_NODE_H
#include "../types/types.h"

// TODO Put them in Types.h file without Errors.

#define t_RepeaterId std::tuple<int,int,int>
#define t_Coordinate std::tuple<int,int,int>
#define t_Neighbours vector<c_Node*>
#define t_Axis int

using namespace std;

// We were supposed to use something like union
class c_Node {
private:
    int m_SwitchId;
    t_RepeaterId m_RepeaterId;
    int m_Type;
    t_Coordinate m_Xc;
    t_Coordinate m_Yc;
    t_Coordinate m_Zc;
    t_Axis m_Axis;
    t_Neighbours m_Neighbours;
public:
    // We should replace datatypes with coded ones
    c_Node(int id,int type);
    c_Node(tuple<int,int,int> id,int type);
    void f_SetAxis(t_Axis p_Axis);
    void f_SetNeighbour(int p_Index,c_Node* p_Neighbour);
    int f_GetType() const;
};

#endif //INC_3D_NETWORK_ON_CHIP_NODE_H
