#include <bits/stdc++.h>

using namespace std;
    void helper(int v){
        vector<bool> vis(v, false);
        vector<bool> visb(v, false);
        for(int i = 0; i < v; i++){
            // dfs
            if(!vis[i]){
                dfs(i, vis);
            }
            // bfs
            if(!visb[i]){
                bfs(i, visb);
            }
        }
    }

    //bfs print 
    void bfs(int src, vector<bool>& visb){
        queue<int> q;
        // root add
        q.push(src);
        visb[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<< node << " ";
            for(auto e: l[node]){
                if(!visb[e]){
                    visb[e] = true;
                    q.push(e);
                }
            }
        }
        cout << endl;
    }

    //dfs print  // g -- > inside class l
    void dfs(int src, vector<bool>& vis){
        vis[src] = true;
        cout << src << " ";
        for(auto e: l[src]){
            if(!vis[e]){
                dfs(e, vis);
            }
        }
    }