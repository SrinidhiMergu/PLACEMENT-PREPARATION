//usingn dfs

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(checkForCycle(it, node, vis, adj)) return true; 
        }else if(vis[it] && parent!=it){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]){
            checkForCycle(i, -1, vis, adj);
        } 
      }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1,V, E, u, v;
    //cin>>t;
    cin >> V >> E;

    vector<int> adj[V];
    while(t--){
        for(int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        if(isCycle){
            NO;
        }else{
          YES;
        }
    }
    return 0;    
  }
