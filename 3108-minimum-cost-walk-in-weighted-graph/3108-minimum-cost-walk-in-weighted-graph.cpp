class Solution {
public:
vector<int> parent,rank;
int find(int i){
    if(i==parent[i]) return i;
    return parent[i] = find(parent[i]);
}

void Union(int x ,int y){
    int px = find(x),py = find(y);
    if(px==py) return;
    if(rank[px]>rank[py])
      parent[py] = px;
    else if(rank[px]<rank[py])
      parent[px] = py;
    else{
        parent[py] = px;
        rank[px]++;
    }
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
    vector<int> mp(n, INT_MAX);
        for(auto & e : edges){
           int pu = find(e[0]);
       int pv = find(e[1]);
     Union(pu, pv);
   int newPar = find(pu); 
    mp[newPar] = mp[pu] & mp[pv] & e[2];
        }
        vector<int> res;
        for(auto & q : query){
            int u = q[0], v = q[1];
            if(find(u) != find(v)) res.push_back(-1);
            else{
              int x = find(u);
              res.push_back(mp[x]);
               }
            }
            return res;
    }
};