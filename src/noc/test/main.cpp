#include <bits/stdc++.h>
#include "TopologyConfig.h"
#define E_Type_Switch 0
using namespace std;

int main() {

    const char* file_name = "topology.txt";
    //freopen("topology.txt", "r", stdin);
    TopologyConfig* t = new TopologyConfig();
    t->TopologConfig(file_name);
    return 0;
}
