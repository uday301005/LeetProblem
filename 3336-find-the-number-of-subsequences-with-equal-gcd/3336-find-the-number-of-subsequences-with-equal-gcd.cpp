class Solution {
public:
int mod = 1e9+7;
int dp[200][201][201];
 int solve(vector<int> &a, int i ,int g1, int g2){
    if(i==a.size()){
       return g1 == g2;
    }
    if(dp[i][g1][g2] != -1) return dp[i][g1][g2];

    int skip = solve(a,i+1,g1,g2);
    int t1 = solve(a,i+1,gcd(g1,a[i]), g2);
    int t2 = solve(a,i+1,g1,gcd(g2,a[i]));

  return dp[i][g1][g2] =  (1LL*skip+t1+t2)%mod;
 }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0)-1;
    }
};