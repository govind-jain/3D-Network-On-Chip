#include "Floyd-Warshall.h"
vector<vector<int>> f_GetRoutingTable(t_AdjacencyList &p_AdjacencyList) {
    int n = p_AdjacencyList.size();
    vector<vector<int>> l_ShortestDistance(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p_AdjacencyList[i].size(); ++j) {
            l_ShortestDistance[i][p_AdjacencyList[i][j].first] = 1;
            l_ShortestDistance[p_AdjacencyList[i][j].first][i] = 1;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                l_ShortestDistance[i][j] = min(l_ShortestDistance[i][j],
                                               l_ShortestDistance[i][k] + l_ShortestDistance[k][j]);
            }
        }
    }
    return l_ShortestDistance;
}
