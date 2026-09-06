class Solution {
public:
string t,s;
int n,m;
vector<vector<int>> dp;
    int solve(int i,int j){
        if(j == m)    return 1;
        if(i == n)  return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0,skip=0;
        if(s[i] == t[j])
        take = solve(i+1,j+1);
        skip = solve(i+1,j);
     return dp[i][j] = take+skip;
    }
    int numDistinct(string se, string tar) {
        t=tar;
        s=se;

         n = s.size();      
         m = t.size(); 
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=n;i>=0;i--) 
         for(int j=m;j>=0;j--)
           if(j==m) dp[i][j] = 1;
           else if(i==n) dp[i][j] = 0;
           else{
            dp[i][j] = dp[i+1][j];
             if(s[i] == t[j]) {
                        long long val =
                            (long long)dp[i][j] +
                            dp[i + 1][j + 1];

                        dp[i][j] = min(val, (long long)INT_MAX);
                    }
           }
        return dp[0][0];  
  return solve(0,0);
    }
};