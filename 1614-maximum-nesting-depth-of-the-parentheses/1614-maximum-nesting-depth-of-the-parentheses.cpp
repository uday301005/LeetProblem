class Solution {
public:
    int maxDepth(string s) {
        int c = 0;
        stack<char> st;
        for(auto & a :s){
            if(a=='(') st.push(a);
            if(a==')') st.pop();
            c = max(c,(int)st.size());
        }
        return c;
    }
};