class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n = a.size();
        int xo = a[0];
        bool all= a[0] == 0;
          for(int i=1;i<n;i++){
               if(a[i]>0) all = false;
            xo ^= a[i];
          }
          if(all) return 0;
          if(xo==0) return n-1;
          return n;


    }
};