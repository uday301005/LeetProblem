class Solution {
public:
unordered_map<int, vector<int>> adj;
vector<bool> vis;
vector<int> parent,rank;
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
     if(!vis[v])
      dfs(v);
}
int find(int x){
 if(x==parent[x]) return x;

 return parent[x] = find(parent[x]);

}

void Union(int x ,int y){
    int px = find(x);
    int py = find(y);
    if(px==py) return;

    if(rank[px] > rank[py])
     parent[py] = px;
     else if(rank[px] < rank[py])
      parent[px] = py;
    else{
        parent[py] = px;
        rank[px]++;
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vis.resize(n,false);
    rank.resize(n,0);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i] = i;

        for(auto in : invocations){
          adj[in[0]].push_back(in[1]);
            Union(in[0],in[1]);
          }
          
          dfs(k);

 vector<int> res;
 bool all = false;
  for(int i=0;i<n;i++)
    if(!vis[i] && find(i) == find(k) ){
        all = true;
        break;
    }
    if(all)
     for(int i=0;i<n;i++)
     res.push_back(i);
else
 for(int i=0;i<n;i++)
  if(!vis[i] && find(i) != find(k))
   res.push_back(i);

return res;
    }
};