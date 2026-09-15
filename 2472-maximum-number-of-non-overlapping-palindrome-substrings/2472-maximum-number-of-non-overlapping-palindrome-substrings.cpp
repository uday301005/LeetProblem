class Solution {
public:
int n,k;
vector<vector<int>> dp;
vector<vector<bool>> pal;
bool isPalin(string & s, int i, int j){
    while(i<j && s[i] == s[j]){
        i++;
        j--;
    }
    return i>=j;
}
int solve(string & s,int i ,int j){
     if(i >= n || j >= n) return 0;
     if(dp[i][j] != -1) return dp[i][j];
    if(pal[i][j]){
       int  take = 1+solve(s,j+1,j+k);
       int  grow = solve(s,i,j+1);
       int  slide = solve(s,i+1,j+1);
      return dp[i][j] = max({take,grow,slide});
    }
    int gro = solve(s,i,j+1);
    int sli = solve(s,i+1,j+1);

    return dp[i][j] =  max(gro,sli);;
}
    int maxPalindromes(string s, int K) {
        n = s.size();
        if(K==1) return n;
        dp.resize(n+1,vector<int> (n+1,-1));
        pal.resize(n+1,vector<bool> (n+1,false));
        k = K;
         for (int i = n - 1; i >= 0; i--) {
            pal[i][i] = true;
            for (int j = i + 1; j < n; j++) 
                if (s[i] == s[j] && (j - i == 1 || pal[i + 1][j - 1])) 
                    pal[i][j] = true;
        }
        for(int i = n; i>=0;i--)
         for(int j=n;j>=0;j--){
            if(i==n || j==n) {
                dp[i][j] = 0;
            continue;
            }
            if(pal[i][j]){
                int take = 1+(j+k<=n ? dp[j+1][j+k] : 0);
                int grow = j+1<=n ? dp[i][j+1] : 0;
                int slide =  j+1<=n ? dp[i+1][j+1]:0;
                dp[i][j] = max({dp[i][j], take,grow,slide});
            }
            int gro = j+1<=n ? dp[i][j+1] :0;
            int slide = j+1<=n ? dp[i+1][j+1] : 0;
            dp[i][j] = max({dp[i][j],gro,slide});
         }
        return dp[0][k-1];
    }
};