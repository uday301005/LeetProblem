class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto x : knowledge)
        mp[x[0]] = x[1];

        int i=0,n=s.size();
        string res;
        while(i<n){
           if(s[i]=='('){
              int j = i+1;
              string temp;
              while(j<n && s[j] != ')') j++;
            temp += s.substr(i+1,j-i-1);
            if(mp.count(temp))
            res += mp[temp];
            else
            res += '?';
            i=j;
           }
           else
           res += s[i];   
      i++;
        }
        return res;
    }
};