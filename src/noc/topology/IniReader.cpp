#include "IniReader.h"
#include <bits/stdc++.h>
using namespace std;

pair<map<int, pair<int, pair<int, int>>>, vector<vector<pair<int, int>>>> f_Reader(const char *file_name) {
    int n, m;
    cin >> n >> m;
    map<int, pair<int, pair<int, int>>> mp1;
    vector<vector<pair<int, int>>> adj1(n);
    for (int i = 0; i < n; ++i) {
        int x, y, z, p;
        cin >> x >> y >> z >> p;
        mp1[p] = {x, {y, z}};
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    return {mp1, adj1};
}
