
#ifndef INC_3D_NETWORK_ON_CHIP_FLOYD_WARSHALL_H
#define INC_3D_NETWORK_ON_CHIP_FLOYD_WARSHALL_H

#include <bits/stdc++.h>
#include "../types/types.h"
using namespace std;
#define INF 100000000

class FloydWarshall{
public:
    vector<vector<t_DirectionId>> static f_GetRoutingTable(t_AdjacencyList p_AdjacencyList,vector<t_Coordinate> p_CoordinatePositions);
};



#endif //INC_3D_NETWORK_ON_CHIP_FLOYD_WARSHALL_H
