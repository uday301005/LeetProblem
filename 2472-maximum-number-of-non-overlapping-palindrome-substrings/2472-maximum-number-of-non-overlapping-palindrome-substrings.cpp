class Solution {
public:
int n,k;
vector<int> t;
vector<vector<int>> dp;
vector<vector<bool>> pal;

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
int solve(int l){
     if(l<k) return 0;
     if(t[l] != -1) return t[l]; 
     int j = l-1;
    int  res = solve(j);
    for(int i=0;j-i+1>=k;i++)
         if(pal[i][j])
           res =  max(res,1+solve(i));
    return t[l] = res;
}
    int maxPalindromes(string s, int K) {
        n = s.size();
        if(K==1) return n;
        t.resize(n+1,-1);
        dp.resize(n+1,vector<int> (n+1,-1));
        pal.resize(n+1,vector<bool> (n+1,false));
        k = K;
        for(int L=1;L<=n; L++)
         for (int i = 0; i+L <= n; i++) {
           int j = i+L-1;
           if(i==j) pal[i][j] = true;
           else if(i+1==j) pal[i][j] = (s[i]==s[j]);
           else pal[i][j] = (s[i]==s[j]) && pal[i+1][j-1];
        }
        return solve(n);
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