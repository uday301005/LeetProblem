class Solution {
public:
int n;
int dp[2][101][101];
 int solve(int per, int i ,int m,vector<int> & a){
    if(i>=n) return 0;
    if(dp[per][i][m] != -1) return dp[per][i][m];
    int st = 0;
    int res = per == 1 ? -1 : INT_MAX;
    for(int x=1 ; x <= min(2*m,n-i); x++){
        st += a[i+x-1];
        if(per==1)
          res = max(res,st + solve(0,i+x,max(m,x),a) );
        else
           res = min(res,solve(1,i+x,max(m,x),a) );
    }
return  dp[per][i][m] = res;
 }
    int stoneGameII(vector<int>& a) {
        n = a.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,0,1,a);
    }
};