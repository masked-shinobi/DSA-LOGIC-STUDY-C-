//DFS
bool cycliccheck(Graph* g, vector<bool>& vis, int parent,  int src){
    vis[src] = true;
    for( int e : g->l[src]){
        if(!vis[e]){
            if(cycliccheck(g, vis, src, e)){
                return true;
            }
        }else if(e != parent){
            return true;
        }
    }
    return false;
}

void cycle(Graph* g){
    vector<bool> vis(g->v, 0);
    bool iscycle = false;
    for( int i= 0; i < g->v; i++){
        if(!vis[i]){
            if(cycliccheck(g, vis, -1, i)){
                iscycle = true;
            }
        }
    }
}

//BFS
bool bfscycle(Graph* g, vector<bool>& vis, int src, int parent){
    queue<pair<int, int>> q;
    q.emplace(src, parent);
    vis[src] = true;
    while(!q.empty()){
        int node1 = q.front().first; // src
        int node2 = q.front().second;// parent
        q.pop();
        for( int e : g->l[node1]){
            if(!vis[e]){
                vis[e] = true;
                q.emplace(e, node1);
            }else if(e != node2){
                return true;
            }
        }
    }
    return false;
}

void bfs_helper(Graph* g){
    vector<bool> vis(g->v, false);
    bool iscycle = false;
    for( int i = 0; i < g->v; i++){
        if(!vis[i]){
            if(bfscycle(g, vis, i, -1)){
                iscycle = true;
            }
        }
    }
    if(iscycle){
        cout << "1";
    }else{
        cout << "0";
    }
}