class Solution {
public:
int n,mx=0;
unordered_set<string> st;
vector<string> res;
 void solve(string& s,string & cur,int i, int c){
    if(c<0) return;
    if(i==n){
        if(c==0) {
            if(cur.size()>mx){
                mx = cur.size();
                st.clear();
            }
            if(mx==cur.size())
           st.insert(cur);
        }
        return;
    }
    if(s[i]!='(' && s[i] != ')'){
        cur.push_back(s[i]);
        solve(s,cur,i+1,c);
        cur.pop_back();
        return;
    }
    solve(s,cur,i+1,c);
    cur.push_back(s[i]);
    solve(s,cur,i+1,c+(s[i]=='(' ? 1 : -1));
    cur.pop_back();
 }
    vector<string> removeInvalidParentheses(string s) {
         n=s.size();
         string cur ="";
       solve(s,cur,0,0);
return vector<string>(begin(st),end(st));
    }
};