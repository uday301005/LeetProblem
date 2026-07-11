class Solution {
public:

unordered_map<int,vector<int>>  adj;

vector<bool> vis;
void check(int u,int & ed , int & nod){
    vis[u] = true;
    nod++;
    ed += adj[u].size();
    for(auto &v :adj[u])
        if(!vis[v])
         check(v,ed,nod);
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {     
     adj.clear();
         vis.assign(n, false);
        
        for(auto & ed : edges){
            int u = ed[0] , v= ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        for(int i=0;i<n;i++)
             if(!vis[i]){ 
              int ed = 0, nod = 0;
              check(i,ed,nod);
              ed /=2;
              if(ed == nod*(nod-1)/2)
             ans++;
        }
        return ans;
    }
};