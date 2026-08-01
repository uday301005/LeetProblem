class Solution {
public:
unordered_map<int,vector<int>> adj;
int t=0;
vector<vector<int>> res;
vector<int> dt,low;

void dfs(int u,vector<bool> & vis, int pu){
    vis[u] = true;
    dt[u] = low[u] = ++t;
    for(int v: adj[u])
    if(!vis[v]){
        dfs(v,vis,u);
        low[u] = min(low[u],low[v]);
        if(low[v] > dt[u])
         res.push_back({u,v});
    }
    else if(v != pu)
    low[u] = min(low[u],dt[v]);
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dt.resize(n);
        low.resize(n);
        vector<bool> vis(n,false);
        for( auto & edge : connections){
            int u = edge[0] , v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //  for (int i = 0; i < n; i++) 
        //     if (!vis[i]) 
                dfs(0, vis, -1);
            
      return res;  
    }
};