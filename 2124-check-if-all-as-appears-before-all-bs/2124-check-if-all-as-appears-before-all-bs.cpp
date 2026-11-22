class Solution {
public:
    bool checkString(string s) {
        int idx=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
              if(idx==-1) idx=i;

            }
            else {
                if(idx!=-1) return false;
            }
        }
        return true;
    }
};