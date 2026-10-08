class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string res;
        for(char ch : s){
            if(ch=='('){ c++;  if(c!=1) res.push_back(ch);}
            else { if(c!=1) res.push_back(ch); c--;}
           
        }
        return res;
    }
};