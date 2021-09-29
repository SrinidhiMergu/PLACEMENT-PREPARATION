vi bfsOfGraph(int V, vi adj[]){
    vi vis(V+1, 0);
    vi bfs;
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.pb(node);
                for(int x : adj[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }
                }
            }
        }
    }
    return bfs;
}

int main() {
    NFS;
    int V, E;
    cin>>V>>E;
    vi adj[V+1];
    int u, v;
    rep(i, E){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi bfs = bfsOfGraph(V, adj);
    fore(bfs); // 3 1 4 2
    //3 4 1 2
    return 0;
}
// TC = O(V+E)
// t1 (adjacency list) - o(E)
// t2 (tree traversal) - o(V)
// TC = t1+t2 = o(V) +o(E) = O(v+E)
// SC - O(V + E) + O(V)  = (adj list + queue)
// adj matrix takes O(V^2) tc
