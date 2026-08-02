class Solution {
public:
int dp[500][500];
int solve(vector<int> & a, int  i, int j){
    if(i>j) return 0;
       if(i==j) return a[i];
       if(dp[i][j] != -1) return dp[i][j];
    int ti = a[i] + min( solve(a,i+2,j),solve(a,i+1,j-1) );
    int tj = a[j] + min( solve(a,i,j-2), solve(a,i+1,j-1) );

    return dp[i][j] = max(ti,tj);
}
    bool stoneGame(vector<int>& a) {
        int n  =  a.size(),  sum = accumulate(begin(a),end(a),0);
        memset(dp,-1,sizeof(dp));
         int  k= solve(a,0,n-1);
         cout<<k<<endl;
    return 2*k>sum;

    }
};