class Solution {
public:
    int scoreOfParentheses(string s) {
     int sc=0,n=s.size();
     stack<int> st;
     for(int i=0;i<n;i++)
        if(s[i]=='('){
            st.push(sc);
           sc=0;
        }
        else {
          if(s[i-1]=='(')
            sc = st.top()+1;
         else 
           sc = st.top()+2*sc;
          st.pop();
        }
        return sc;  
    }
};