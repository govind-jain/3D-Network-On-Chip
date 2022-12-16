#include "TopologyConfig.h"

void f_Swap(int &u, int &v, vector<t_Coordinate > &p_Coordinates) {
    if (get<0>(p_Coordinates[u]) != get<0>(p_Coordinates[v])) {
        if (get<0>(p_Coordinates[u]) > get<0>(p_Coordinates[v])) {
            swap(u, v);
        }
    } else if (get<1>(p_Coordinates[u]) != get<1>(p_Coordinates[v])) {
        if (get<1>(p_Coordinates[u]) > get<1>(p_Coordinates[v])) {
            swap(u, v);
        }
    } else {
        if (get<2>(p_Coordinates[u]) > get<2>(p_Coordinates[v])) {
            swap(u, v);
        }
    }
}

pair<vector<t_Coordinate>, t_AdjacencyList> f_Reader() {
    int n, m;
    cin >> n >> m;
    vector<t_Coordinate> l_Coordinates(n);
    t_AdjacencyList l_AdjacencyList(n);
    for (int i = 0; i < n; ++i) {
        int x, y, z, p;
        cin >> x >> y >> z >> p;
        tuple<int, int, int> l_Coordinate = {x, y, z};
        l_Coordinates[p] = l_Coordinate;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        f_Swap(u,v,l_Coordinates);
        l_AdjacencyList[u].push_back({v, w});
    }
    return make_pair(l_Coordinates, l_AdjacencyList);
}

void TopologyConfig::f_SetTopology() {
    pair<vector<t_Coordinate>, t_AdjacencyList> p = f_Reader();
    m_Position = p.first;
    m_Neighbours = p.second;
    m_NumNodes = m_Position.size();
    cout << "(Debug)" << m_NumNodes << endl;
}

t_AdjacencyList TopologyConfig::f_GetNeighbours() {
    return m_Neighbours;
}

vector<t_Coordinate> TopologyConfig::f_GetPositions() {
    return m_Position;
}

int TopologyConfig::f_GetNumNodes() {
    return m_NumNodes;
}