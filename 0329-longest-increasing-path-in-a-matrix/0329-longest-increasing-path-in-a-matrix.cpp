class Solution {
public:
int n ,m;
int dis[4][2] = {{-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>> dp;
int solve(vector<vector<int>>& a , int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];

    int c=1;
     for(auto d : dis){
        int i_ = d[0] +i;
        int j_ = d[1] +j;
        if(i_>=0 && i_<n && j_>=0 && j_<m && a[i][j] < a[i_][j_])
        c = max(c,1+solve(a,i_,j_));
     }
     return dp[i][j] =  c;
}

    int longestIncreasingPath(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        dp.assign(n, vector<int>(m, -1));
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         ans = max(ans,solve(a,i,j));
        
        return ans;
    }
};