class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int n = a.size();
        vector<int> freq(n+1,0);

        for(int i=0;i<n;i++) freq[min(a[i],n)]++;

        int ans=1;
        for(int i=1;i <= n;i++) 
            ans = min(ans+freq[i],i);
return ans;
    }
};