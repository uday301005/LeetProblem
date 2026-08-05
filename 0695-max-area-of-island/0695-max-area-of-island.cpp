class Solution {
public:
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1} };
vector<vector<bool>> vis;
int n,m;

int dfs(vector<vector<int>> & a, int i,int j){
    if(i<0 || i>=n || j>=m || j<0 || a[i][j] == 0 || vis[i][j]) return 0;
    vis[i][j] = true;
    int c=1;
    for(auto & dis : direction){
        int i_ = i+dis[0], j_ = j+dis[1];
          c +=  dfs(a,i_,j_);
    }
    return c;
}
    int maxAreaOfIsland(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
       vis.resize(n,vector<bool>(m,false));
       int ans= 0;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(!vis[i][j])
          ans = max(ans, dfs(a,i,j));
    return ans;
    }
};