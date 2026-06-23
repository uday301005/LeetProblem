class Solution {
public:
    int n, l, r;
    int dp[2001][2][2001];
    int mod = 1e9 + 7;
    int solve(int i, int dir, int x) {
        if (x < l || x > r)
            return 0;
        if (i == n)
            return 1;

        if (dp[i][dir][x] != -1)
            return dp[i][dir][x];
        int ans = 0;

        if (dir) {
            for (int y = x + 1; y <= r; y++)
                ans = (ans + solve(i + 1, 0, y)) % mod;
        } else {
            for (int y = l; y < x; y++)
                ans = (ans + solve(i + 1, 1, y)) % mod;
        }

        return dp[i][dir][x] = ans % mod;
    }
    int zigZagArrays(int N, int L, int R) {
        n = N;
        l = L;
        r = R;
        int m = r-l+1;
        vector<vector<int>> dp0(n+1, vector<int>(m,0));
        vector<vector<int>> dp1(n+1, vector<int>(m,0));
         
         for(int i=0;i<m;i++) {
            dp0[1][i] = 1;
            dp1[1][i] = 1;
         }
         for(int len=2;len<=n;len++){
            
            vector<int> pre0(m,0), pre1(m,0);

          pre0[0] = dp0[len-1][0];
            pre1[0] = dp1[len-1][0];

            for(int i=1;i<m;i++){
                pre0[i] = (pre0[i-1] + dp0[len-1][i])%mod;
                pre1[i] = (pre1[i-1] + dp1[len-1][i])%mod;
            }
            for(int i=0;i<m;i++){
                if(i>0) dp1[len][i] = pre0[i-1];
                int tot = pre1[m-1];
                dp0[len][i] = (tot-pre1[i] + mod)%mod;
            }

         }
        int ans = 0;
        for (int i = 0; i<m; i++) {
            ans = (ans +dp1[n][i] ) % mod;
            ans = (ans + dp0[n][i] ) % mod;
        }
        return ans;
    }
};