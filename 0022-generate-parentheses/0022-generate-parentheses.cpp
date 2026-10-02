class Solution {
public:
vector<string> res;
int n;
   void solve(string s,int o, int c ){
    if(s.size()>=2*n){
        res.push_back(s);
        return;
    }
    if(o<n)
    solve(s+'(',o+1,c);
    if(c<o)
    solve(s+')',o,c+1);
   }
    vector<string> generateParenthesis(int N) {
        n=N;
        solve("",0,0);

        return res;
    }
};