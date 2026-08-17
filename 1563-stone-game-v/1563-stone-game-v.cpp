class Solution {
public:

vector<int> pre;
vector<vector<int>> dp;
int dfs(vector<int> & a , int i ,int j){
    if(i>j) return -1e9;
    if(i == j) return 0;
    if(dp[i][j] != -1)  return dp[i][j];
     int res = 0;
     for(int k = i ; k<j ;k++){
        int sum1 = pre[k] - ((i>0) ? pre[i-1]  : 0);
        int sum2 = pre[j] -  pre[k];
        if(sum1 < sum2)
          res = max(res, sum1 + dfs(a,i,k));
        else if(sum2 < sum1)
         res = max(res,sum2 + dfs(a,k+1,j));
        else
         res = max({res,sum1+dfs(a,i,k),sum2+dfs(a,k+1,j)});
     }
     return dp[i][j] = res;
}
    int stoneGameV(vector<int>& a) {
        int  n = a.size();
        pre.resize(n);
        dp.resize(n,vector<int> (n,-1));
        pre[0] = a[0];
        for(int i=1;i<n;i++) pre[i] = a[i]+pre[i-1];
        int res = dfs(a,0,n-1);
  return res;
    }
};