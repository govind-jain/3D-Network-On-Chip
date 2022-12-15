#include <vector>
#include <string>

#ifndef TYPES_H
#define TYPES_H

typedef unsigned int t_NodeId;
typedef unsigned int t_Coordinate;
typedef unsigned int t_Axis;
typedef std::string t_FileName;
typedef unsigned short t_NodeType;
typedef vector<vector<vector<char>>> t_Topology;

enum t_DirectionId{
    E_Type_Switch = 0,
    E_Type_Repeater = 1,

    E_Prev = 0,
    E_Next = 1,

    E_East=0,
    E_West=1,
    E_North = 2,
    E_South = 3,
    E_Up = 4,
    E_Down = 5,

    E_Repeater_Size = 2,
    E_Switch_Size = 6
};

#endif