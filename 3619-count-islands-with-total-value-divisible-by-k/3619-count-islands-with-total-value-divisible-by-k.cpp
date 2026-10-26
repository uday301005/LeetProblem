class Solution {
public:
vector<vector<int>> a;
vector<vector<bool>>vis;
int n,m;
int dis[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
long long solve(int r,int c){
     
    vis[r][c] = true;
    long long ans=a[r][c];
    
    for(auto d : dis){
        int i = r+d[0];
        int j = c+d[1];
        if(i<0 || i>=n || j<0 || j>=m || a[i][j]==0 || vis[i][j]) continue;
         ans += solve(i,j);
    }
  return ans;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        a = grid;
        n = a.size();
        m = a[0].size();
        vis.resize(n,vector<bool>(m,false));
        int c=0;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(!vis[i][j] && a[i][j] != 0)
            if(solve(i,j)%k==0)
              c++;
          
        return c;
    }
};