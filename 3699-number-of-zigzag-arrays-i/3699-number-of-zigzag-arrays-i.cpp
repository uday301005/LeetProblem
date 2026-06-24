class Solution {
public:
int n,m,mod=1e9+7;
int dp[2001][2001][2];
int solve(int i,int x,bool up){
    if(i==n)   return 1;
    if(dp[i][x][up]!=-1) return dp[i][x][up];
    int res=0;
          if(up){
          for(int st = x+1; st<=m ; st++)
          res = (res+solve(i+1,st,false))%mod;
          }
          else{
          for(int st=1;st<x;st++)
          res = (res + solve(i+1,st,true))%mod;
          }
    return dp[i][x][up] = res%mod;
}
    int zigZagArrays(int N, int l, int r) {
        m = r-l+1;
        n = N;
        memset(dp,-1,sizeof(dp));
        int res=0; 
        //  for(int st=1;st<=m;st++){
        //      res = (res + solve(1,st,true))%mod;
        //      res = (res + solve(1,st,false))%mod;
        //  }
          static int cur[2002][2], nxt[2002][2];
    static int pref0[2002], pref1[2002];

    for(int val=1; val<=m; val++){
        cur[val][0] = 1;
        cur[val][1] = 1;
    }
          for(int i=N-1; i>=1; i--){

        pref0[0] = 0;
        pref1[0] = 0;

        for(int val=1; val<=m; val++){
            pref0[val] = (pref0[val-1] + cur[val][0]) % mod;
            pref1[val] = (pref1[val-1] + cur[val][1]) % mod;
        }

        for(int val=1; val<=m; val++){
            nxt[val][1] = (pref0[m] - pref0[val] + mod) % mod;
            nxt[val][0] = pref1[val-1];
        }
        for(int val=1; val<=m; val++){
            cur[val][0] = nxt[val][0];
            cur[val][1] = nxt[val][1];
        }
    }
        for(int st=1;st<=m;st++){
            res = (res+cur[st][0])%mod;
            res = (res+cur[st][1])%mod;
        }
         return res;
    }
};