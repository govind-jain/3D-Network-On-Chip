#include "TopologyConfig.h"
#include "IniReader.h"
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

map<int, pair<int, pair<int, int>>> mp;
vector<vector<pair<int, int>>> adj;


void TopologyConfig:: TopologConfig(const char *file_name) {
    pair<map<int, pair<int, pair<int, int>>>, vector<vector<pair<int, int>>>> p = f_Reader(file_name);
    mp = p.first;
    adj = p.second;

    cout<<adj.size()<<endl;

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

