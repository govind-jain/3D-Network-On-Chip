#ifndef INC_3D_NETWORK_ON_CHIP_TYPES_HPP
#define INC_3D_NETWORK_ON_CHIP_TYPES_HPP

#include <bits/stdc++.h>

using namespace std;

typedef std::string t_FileName;
typedef std::vector<list<pair<int,int>>> t_AdjacencyList;
typedef double t_Distance;
typedef std::vector<vector<t_Distance>> t_AdjacencyMatrix;
typedef short t_NodeType;
typedef int t_SwitchId;
typedef int t_Coordinate;
typedef std::tuple<int,int,int> t_Coordinates;
typedef std::tuple<int,int,int> t_RepeaterId;
typedef int t_Axis;
typedef int t_DirectionIndex;
typedef int t_RoutingAlgo;
typedef vector<vector<t_DirectionIndex>> t_SwitchRoutingTable;
//typedef vector<unordered_map<t_RepeaterId, t_DirectionIndex>> t_RepeaterRoutingTable;
typedef unordered_map<t_RepeaterId, vector<t_DirectionIndex>> t_RepeaterRoutingTable;

enum t_NodeProperties{
    E_Type_Switch = 0,
    E_Type_Repeater = 1,

    E_Repeater_Size = 2,
    E_Switch_Size = 6
};

enum t_AxisTypes{
    E_XAxis = 0,
    E_YAxis =1,
    E_ZAxis = 2
};

enum t_DirectionIndices{
    E_NotDefined = -1,

    E_Prev = 0,
    E_Next = 1,

    E_East=0,
    E_West=1,
    E_North = 2,
    E_South = 3,
    E_Up = 4,
    E_Down = 5,
};

enum t_RoutingAlgorithms{
    E_ShortestPathRouting = 1
};

#endif //INC_3D_NETWORK_ON_CHIP_TYPES_HPP
