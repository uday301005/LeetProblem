class Solution {
public:
vector<int> dp;
int dfs(int n){
    if(n<=0)
        return 0;
        if(dp[n] != -1) return dp[n];
      for(int i = 1 ; i*i <=n ;i++)
        if(dfs(n-i*i)==0) return  1;
      return dp[n] = 0 ;
}
    bool winnerSquareGame(int n) {
     dp.resize(n+1,-1);
      return dfs(n);   
    }
};