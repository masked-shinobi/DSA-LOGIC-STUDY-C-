#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int v; // vertex
    vector<vector<int>> l;
    Graph(int v){
        this->v = v;
        l.resize(v);
    }
};

void graph_creation(vector<vector<int>> edges, Graph* g){
    for( auto x : edges ){
        int u = x[0];
        int v = x[1];

        g->l[u].push_back(v);
        g->l[v].push_back(u);
    }
}

// function given with edges and the graph class

int main() {


    return 0;
}