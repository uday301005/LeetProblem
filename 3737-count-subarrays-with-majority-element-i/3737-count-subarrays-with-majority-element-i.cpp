class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int t) {
        int n = a.size();
       int ans=0;
       for(int i=0;i<n;i++){
        int c=0;
        for(int j=i;j<n;j++){
            if(a[j]==t) c++;
            else c--;
            if(c>0) ans++;
        }
       }
       return ans;
    }
};