class Solution {
public:
int n,mod=1e9+7 ;
vector<vector<pair<int,int>>> dp;
   pair<int,int> mxsc(vector<string> & a ,int i,int j){
    if(i<0 || j<0 || a[i][j] == 'X') return {-1,0};
    if(i==0 && j==0) return {0,1};
    if(dp[i][j].first != INT_MIN) return dp[i][j];
    int c = (a[i][j] >= '0' && a[i][j] <= '9') ? a[i][j]-'0' : 0;
    pair<int,int> up =  mxsc(a,i-1,j);
    pair<int,int> left = mxsc(a,i,j-1);
    pair<int,int> dig = mxsc(a,i-1,j-1);
    int best = max({up.first,left.first,dig.first});
    if(best == -1) return dp[i][j] =  {-1,0}; 
    int w=0;
    if(up.first==best) w = (w+up.second)%mod;
    if(left.first==best) w = (w+left.second)%mod;
    if(dig.first==best) w = (w+dig.second)%mod;

    return dp[i][j] = {best+c , w};
}
  vector<int> pathsWithMaxScore(vector<string>& a) {
    n = a.size();
    dp.assign(n, vector<pair<int,int>>(n, {INT_MIN, 0}));
    auto [s,c] = mxsc(a,n-1,n-1);
    if(s == -1) return {0,0};
    return {s, c};
}
};


































