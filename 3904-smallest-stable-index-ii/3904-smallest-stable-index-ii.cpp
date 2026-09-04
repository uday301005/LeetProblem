class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        vector<int> mx(n);
        mx[0] = a[0];
        for(int i=1;i<n;i++)
         mx[i] = max(mx[i-1],a[i]);

        int mn = a[n-1],idx=-1;
        for(int i=n-1;i>=0;i--){
            mn = min(a[i],mn);
           if(mx[i]-mn<=k)
            idx=i;
        }
        return idx;
    }
};