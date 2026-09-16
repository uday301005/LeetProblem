class Solution {
public:
int mod = 1e9+7;
vector<vector<int>> dp;
  int solve(int n,int k){
       if(k==0) return 1;
       if(n<=0) return 0;
       if(dp[n][k] != -1) return dp[n][k];
    int skip = solve(n-1,k);
    int take = 0;
    for(int i=n-1;i>0;i--)
      take = (take + solve(i,k-1))%mod;
 return dp[n][k] = (take+skip)%mod;
  }
    int numberOfSets(int N, int K) {
        if(N == K+1) return 1;
        dp.resize(N+1,vector<int> (K+1,-1));
    //    for(int n= 0 ; n<=N;n++){
    //       for(int k=0;k<=K;k++){
    //            if(n<=0) dp[n][k] = ;
    //       }
    //     }
        return solve(N,K);
    }
};