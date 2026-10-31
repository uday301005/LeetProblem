class Solution {
public:
int mod = 1e9+7,n,m;
int dp[501][501][2];
 int solve(vector<vector<int>>& a,int i,int j,int s){
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(i==n-1 && j==m-1) return 1;
    if(dp[i][j][s]!=-1) return dp[i][j][s];
     int total = 0;
    if(a[i][j]==0){
        total = (total+solve(a,i,j+1,0))%mod;
        total = (total+solve(a,i+1,j,1))%mod;
    }
    else{
        if(s==0)
        total = (total+solve(a,i+1,j,1))%mod;
        else
        total = (total+solve(a,i,j+1,0))%mod;
    }
    return dp[i][j][s] = total;
 }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};