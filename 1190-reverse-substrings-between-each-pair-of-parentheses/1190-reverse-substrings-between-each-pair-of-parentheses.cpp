class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for(char x : s){
            if(x=='(')
            st.push(res.size());
            else if(x==')'){
             int t=st.top();
             st.pop();
            reverse(res.begin()+t,res.end());
            }
            else
            res.push_back(x);
        }
return res;
    }
};