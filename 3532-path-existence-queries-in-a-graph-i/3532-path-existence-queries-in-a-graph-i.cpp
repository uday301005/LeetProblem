class Solution {
public:
vector<int>parent;


int find(int x){
    if(parent[x]==x) return x;
    return parent[x] =  find(parent[x]);
}
void Union(int x , int y){
  int px = find(x), py = find(y);
  if(px!=py) parent[px] = py; 
}
    vector<bool> pathExistenceQueries(int n, vector<int>& a, int maxDiff, vector<vector<int>>& queries) {
      
          for(int i=0;i<n;i++) parent.push_back(i);

        unordered_map<int,set<int>> adj;
         vector<pair<int,int>> vp;
     for(int i=0;i<n;i++)
       vp.push_back({a[i], i});
     sort(vp.begin(), vp.end());
      
          for(int i=0;i<n-1;i++)
           if(vp[i+1].first - vp[i].first <= maxDiff)
                  Union(vp[i+1].second,vp[i].second);
        vector<bool> res;
         for(auto & q: queries){
            int u = q[0] , v= q[1];
            if(find(u)== find(v))
              res.push_back(true);
            else 
              res.push_back(false);
         }
         return res;
    }
};