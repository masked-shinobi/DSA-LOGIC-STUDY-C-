//BFS
vector<int> topologicalsort(Graph* g, vector<int>& result){
    //bfs logic
    vector<int> indegree(g->v, 0);
    // calculate indegree
    for( int i = 0; i < g->v; i++){
        for( int e: g->l[i]){
            indegree[e]++;
        }
    }
    // intialise queue with indegree 0
    queue<int> q;
    for( int i = 0; i< indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i); // push vertex not the indegree value
        }
    }
    // bfs logic
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);
        for( int v : g->l[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v); // push vertex not the indegree value
            }
        }
    }
    return result;
}

//DFS
// topological dfs
void topologicaldfs(Graph* g, vector<bool>& vis, int src, stack<int>& s){
    vis[src] = true;
    for( int e : g->l[src] ){
        if(!vis[e]){
            topologicaldfs(g, vis, e, s);
        }
    }
    s.push(src);
}

void dfshelper(Graph* g){
    vector<bool> vis(g->v, false);
    stack<int> s;
    for( int i = 0 ; i < g->v; i++){
        if(!vis[i]){
            topologicaldfs(g, vis, i, s);
        }
    }
    cout << "Topological sorted is : ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}