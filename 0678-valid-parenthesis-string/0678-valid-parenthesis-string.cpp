class Solution {
public:
int n;
vector<vector<int>> dp;
bool check(string & s,int i, int c){
    if(c<0) return false;
    if(i==n){
        return c==0;
    }
    bool ans = false;
    if(s[i]=='(') ans = check(s,i+1,c+1);
    else if(s[i]==')') ans=check(s,i+1,c-1);
    else{
        if(check(s,i+1,c)||check(s,i+1,c+1)||check(s,i+1,c-1))
       ans = true;
    }
return ans;
}

    bool checkValidString(string s) {
        n = s.size();
        dp.resize(n + 1, vector<int>(n + 1, 0));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) 
            for (int c = 0; c <= n; c++)
                if (s[i] == '(') {
                    if (c + 1 <= n)
                        dp[i][c] = dp[i + 1][c + 1];
                }
                else if (s[i] == ')') {
                    if (c > 0)
                        dp[i][c] = dp[i + 1][c - 1];
                }
                else {   
                   dp[i][c] = dp[i + 1][c];
                    if (c + 1 <= n)
                        dp[i][c] |= dp[i + 1][c + 1];
                    if (c > 0)
                        dp[i][c] |= dp[i + 1][c - 1];
                }
        return dp[0][0];
    }
};