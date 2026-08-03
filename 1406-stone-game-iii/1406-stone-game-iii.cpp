class Solution {
public:
int n ;
vector<int>dp;

 int dfs(vector<int> &a ,int i){
  if(i>=n) return 0;
  if(dp[i] != -1) return dp[i];

    int ti = INT_MIN;
    ti = max( ti, a[i] - dfs(a,i+1) );

    if(i+1<n)
     ti = max( ti, a[i]+a[i+1] - dfs(a,i+2) );

     if(i+2<n)
      ti = max( ti, a[i]+a[i+1]+a[i+2] - dfs(a,i+3) );
  return dp[i] = ti;
 }
    string stoneGameIII(vector<int>& a) {
         n = a.size();
         dp.resize(n,-1);
          int p1 = dfs(a,0);
         if(2*p1 > 0) return "Alice";
         else if ( 2*p1<0 ) return "Bob";
         return "Tie";

    }
};