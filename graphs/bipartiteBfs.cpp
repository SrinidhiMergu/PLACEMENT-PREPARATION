bool bfsCheck(int src, vi color, vi adj[]){
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
        int node = q.front();
        //color[node]=1;
        q.pop();
        for(int x : adj[node]){
            if(color[x] == -1){
                q.push(x);
                color[x]=1-color[node];
            }
            else if(color[x]==color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vi adj[]){
    vi color(V+1, -1);

    for(int i=1; i<=V; i++){
        if(color[i]==-1){
            if(!bfsCheck(i, color, adj)) {
                return false;
            }
            //else return false;
        }
    }
    return true;

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
    if(isBipartite(V, adj)) yes;
    else no;
    return 0;
}
