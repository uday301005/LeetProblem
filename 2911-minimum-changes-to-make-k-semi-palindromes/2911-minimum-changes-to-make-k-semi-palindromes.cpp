class Solution {
public:
int n;
vector<vector<int>> dp,divisor;
int cost(string & s,int st,int end){
    int len=end-st+1,mc=INT_MAX;
    for(int d : divisor[len]){
        int c=0;
        for(int g=0;g<d;g++){
            int l = st+g;
            int r=l + ((len / d) - 1) * d;
            while(l<r){
                if(s[l]!=s[r]) c++;
                l+=d;
                r-=d;
            }
        }
        mc= min(mc,c);
    }
return mc;
}
int solve(string & s,int st,int k){
    if(k==0)
        return st == n ? 0 : INT_MAX;
    if(n - st < 2 * k) return INT_MAX;
    if(dp[st][k] != -1) {
            return dp[st][k];
        }
    int mn=INT_MAX;
    for(int end=st;end<n;end++){
        int rm = solve(s,end+1,k-1);
        int cs= cost(s,st,end);
        if(rm != INT_MAX && cs != INT_MAX)
    mn = min(mn, cs + rm);
    }
    return dp[st][k] = mn;
}
    int minimumChanges(string s, int k) {
        n = s.size();
       dp.resize(n+1,vector<int>(k+1,-1));
       divisor.resize(n+1);
       for(int d = 2; d <= n; d++) 
       for(int i = 1; i * i <= d; i++) 
        if(d % i == 0) {
            if(i < d)
                divisor[d].push_back(i);

            if(i != d/i && d/i < d)
                divisor[d].push_back(d/i);
        }
    

        return  solve(s,0,k);
    }
};