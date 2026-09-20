class Solution {
public:
 string res;
unordered_set<string> vis;
    void solve(string& s){
      vis.insert(s);
        if (s < res)
            res = s;
        for(int i=0;i+1<s.size();i++)
        if (abs(s[i] - s[i + 1]) == 1 || abs(s[i]-s[i+1])==25) {
            string temp = s.substr(0, i) + s.substr(i + 2);
            solve(temp);
        }
    }
    vector<vector<string>> dp;
    bool is(char & a, char & b){
        int d = abs(a-b);
        return d==1 || d==25;
    }
    string solve(string & s, int l,int r){
        if(l==r) return string(1,s[l]);
        if(l>r) return "";
        if(dp[l][r] != "#") return dp[l][r];

        string ans = s[l] + solve(s,l+1,r);
        for(int k=l+1;k<=r;k++){
            if(is(s[l],s[k]) && solve(s,l+1,k-1) ==  "")
           ans = min(ans,solve(s,k+1,r));
        }
return dp[l][r] = ans;
    }

    string lexicographicallySmallestString(string s) {
        int n=s.size();
        dp.resize(n+1,vector<string>(n,""));
        for(int l=0; l<=n-1; l++)
            dp[l][l] = string(1, s[l]);
        for(int l=n-2;l>=0;l--){
            for(int r=l+1;r<n;r++){
                    string res = s[l] + dp[l+1][r];
                    for(int k=l+1;k<=r;k++)
                      if(is(s[l],s[k]) && dp[l+1][k-1]== "")
                      res = min(res,dp[k+1][r]);
              dp[l][r] = res;
            }
        }
        return dp[0][n-1];
       res = s;
        solve(s);
        return res;
    }
};