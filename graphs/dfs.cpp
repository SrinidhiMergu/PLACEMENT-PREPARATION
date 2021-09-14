#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define NFS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int> 
#define pb push_back
#define ull unsigned long long
#define rep(i, n) for(int i=0;i<n;++i)
#define repn(i, n) for(int i=1;i<=n;++i)
#define fore(arr) for (auto &x : (arr))
#define mp make_pair
#define bug cout << "*_*\n"
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define no cout << "no" << endl

int cnt=0;

void print(vector<T> v)
{
    fore(v) cout << x << ' ';
    cout << endl;
}
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
    storeDfs.pb(node); 
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, storeDfs); 
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
        vector<int> storeDfs; 
        vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]){
            dfs(i, vis, adj, storeDfs);
            cnt++;
        } 
      }
        return storeDfs; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1,V, E, u, v;
    //cin>>t;
    cin >> V >> E;
    // adjacency list
    vector<int> adj[V];
    while(t--){
        for(int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int>ans = obj.dfsOfGraph(V, adj);
        print(ans);
    }
    return 0;
}
