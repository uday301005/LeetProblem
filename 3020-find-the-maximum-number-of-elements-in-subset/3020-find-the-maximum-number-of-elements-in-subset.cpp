class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        int  ans=1;
        for(auto & it : mp){
            int val = it.first;
            if(val == 1){
                int c = mp[val];
                if(c%2==0) c--;
                ans = max(ans, c);
                continue;
             }
            int res=0;
             while(true){
                long long nxt = 1LL * val * val;
                // if(val > 1e9 / val) break;

                 int curr = mp[val];
                 if(!mp.count(nxt) || curr == 1) {
                    res++;
                    break;
                 }
                res += 2;
                val = nxt;
             }
             ans = max(ans,res);
        }
  return ans;
    }
};