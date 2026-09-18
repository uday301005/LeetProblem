class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> idx(26,vector<int>(2,-1));
        vector<string> res;
        int n=s.size();
        for(int i=0;i<n;i++){
          int  num = s[i]-'a';
          if(idx[num][0] == -1) idx[num][0] = i;
          idx[num][1] = i;
         }
         vector<int> valid(n,true);
         for(int i=n-1;i>=0;i--){
            int num = s[i]-'a';
            int st = idx[num][0];
            if(st<i) valid[i] = false;
         }
         for(int c=0;c<26;c++){
            if(idx[c][0] == -1) continue;
            for(int i= idx[c][0]+1 ; i<idx[c][1] ;i++){
                if(idx[s[i]-'a'][0]< idx[c][0]) {
                    valid[idx[c][0]] = false;
                    // idx[c][0] = idx[c][1] = -1;
                    break;
                }
                if(idx[s[i]-'a'][1] > idx[c][1])
                idx[c][1] = idx[s[i]-'a'][1];
            }
         }
          for(int i=0;i<26;i++){
            cout<<(char)(i+'a')<<" "<<idx[i][0]<<" "<<idx[i][1]<<endl;
         }
         int lastIdx=n;
         for(int i=n-1;i>=0;i--){
             int c = s[i]-'a';
             if(!valid[i]) continue;
             if(idx[c][0]==i && idx[c][1]<lastIdx) {res.push_back(s.substr(i,idx[c][1]-i+1));
             lastIdx = i;
             }
         }
         return res;
    }
};