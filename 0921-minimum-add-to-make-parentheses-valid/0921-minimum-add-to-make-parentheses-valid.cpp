class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0,ans=0;
        for(char x : s){
           if(x=='(')
            c++;
           else{
             if(c>0) c--;
             else ans++;
           }
        }
        if(c>0) ans += c;
        return ans;
    }
};