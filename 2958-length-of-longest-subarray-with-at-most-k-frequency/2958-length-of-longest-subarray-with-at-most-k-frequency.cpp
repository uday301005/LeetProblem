class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        int st=0,end=0,ans=0,mf=0,me = 0;
        unordered_map<int,int> mp;
        while(true){
          if(mf <= k){
              if(end<n){
                 mp[a[end]]++;
                  if(mp[a[end]] > mf){
                    mf = mp[a[end]];
                    me = a[end];
                  }
                end++;
              }
              else
              break;
          }
          else{
            if(st<n){
            int x = a[st];
            if(x==me) mf--;
            mp[x]--;
          st++;
            }
            else break;
          }
          if(mf <= k)
          ans = max(ans,end-st);
        }
        return ans;
    }
};