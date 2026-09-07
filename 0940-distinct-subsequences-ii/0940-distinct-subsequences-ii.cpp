class Solution {
public:
int mod =1e9+7,dp[2001];
string s;
vector<int> prev;
int solve(int n){
  if(n==0) return 1;
  if(dp[n] != -1) return dp[n];
  int total = (2*solve(n-1))%mod;
  if(prev[n] !=0 ){
  int sub = solve(prev[n]-1);
 total = (total - sub + mod) % mod;
  }
  return dp[n] = total;
}
    int distinctSubseqII(string se) {
        s=se;
        int n = s.size();
          prev.assign(n+1, 0);
        memset(dp,0,sizeof(dp));
        vector<int> lastSeen(26, 0);
        for(int i = 1; i <= n; i++) {
            int idx = s[i-1] -'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int total = (2*dp[i-1])%mod;
            if(prev[i] != 0){
                int sub = dp[prev[i]-1];
                total = (total-sub+mod)%mod;
            }
            dp[i] =total;
        }
                    return (dp[n]-1+mod)%mod;
         return (solve(n)-1+mod)%mod;
    }
};