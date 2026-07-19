class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> idx(26,-1);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
          idx[s[i]-'a'] = i;
        string res;
        for(int i=0;i<n;i++){
           int t = s[i]-'a';
           if(vis[t]) continue;
           while(res.size() > 0 && s[i] < res.back() && idx[res.back()-'a'] > i ){
            vis[res.back()-'a'] = 0;
            res.pop_back();
           }
            res.push_back(s[i]);
            vis[t] = true;
        }
        return res;
    }
};