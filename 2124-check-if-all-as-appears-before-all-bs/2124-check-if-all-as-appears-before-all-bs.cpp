class Solution {
public:
    bool checkString(string s) {
        bool is=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
              if(!is) is=true;
            }
            else if(is)
             return false;
        }
        return true;
    }
};