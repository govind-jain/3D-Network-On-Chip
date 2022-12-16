#include "TopologyConfig.h"

pair<vector<t_Coordinate>, t_Neighbours> f_Reader() {
    int n, m;
    cin >> n >> m;
    vector<t_Coordinate> l_Coordinates(n);
    t_Neighbours l_AdjacencyList(n);
    for (int i = 0; i < n; ++i) {
        int x, y, z, p;
        cin >> x >> y >> z >> p;
        tuple<int, int, int> l_Coordinate = {x, y, z};
        l_Coordinates[p] = l_Coordinate;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        l_AdjacencyList[u].push_back({v, w});
        l_AdjacencyList[v].push_back({u, w});
    }
    return make_pair(l_Coordinates, l_AdjacencyList);
}

void TopologyConfig::f_SetTopology() {
    pair<vector<t_Coordinate>, t_Neighbours> p = f_Reader();
    m_Position = p.first;
    m_Neighbours = p.second;
    m_NumNodes = m_Position.size();
    cout << "(Debug)" << m_NumNodes << endl;
}


/*
 * void CreateTopology(){
    map<int, c_Node *> Switch;
    map<int, c_Node *> Repeater;
    for (int i = 0; i < adj.size(); ++i) {
        if(Switch.find(i) == Switch.end()){
            c_Node *t = new c_Node(i, E_Type_Switch);
            Switch[i] = t;
        }
        for (int j = 0; j < adj[i].size(); ++j) {
            if(Switch.find(adj[i][j].first) == Switch.end()){
                c_Node *t = new c_Node(adj[i][j].first, E_Type_Switch);
                Switch[adj[i][j].first] = t;
            }

        }
    }
}

 */

