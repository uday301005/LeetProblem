class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int res =0,o=0,c=0;
        for(int i=0;i<n;i++){
             if(s[i]=='(') o++;
             else c++;
             if(c>o){
                o=0;
                c=0;
             }
             else if(c==o) 
             res = max(res,o+c);
        }
        o=c=0;
        for(int i=n-1;i>=0;i--){
             if(s[i]=='(') o++;
             else c++;
             if(c<o){
                o=0;
                c=0;
             }
             else if(c==o) 
             res = max(res,o+c);
        }
return res;
    }
};