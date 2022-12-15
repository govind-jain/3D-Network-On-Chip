#ifndef INC_3D_NETWORK_ON_CHIP_NODE_H
#define INC_3D_NETWORK_ON_CHIP_NODE_H

class c_Node {
private:
    t_NodeId l_nodeId;
    t_Coordinate l_xc;
    t_Coordinate l_yc;
    t_Coordinate l_zc;
    t_Axis l_axis;

public:
    int id,type;
    c_Node(int id,int type){
        this->id = id;
        this->type = type;
    }
};

#endif //INC_3D_NETWORK_ON_CHIP_NODE_H
