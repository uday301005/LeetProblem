class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
   int n=a.size();
   for(int i=0;i<n;i++)
   a[i] = abs(a[i]);
   sort(begin(a),end(a));
   long long ans=0;
   for(int i=0;i<n;i++)
         if(i<n/2) ans = ans-1LL*a[i]*a[i];
         else ans = ans+1LL*a[i]*a[i];
   return ans;
    }
};