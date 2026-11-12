class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int ans=1,in=1,de=1;
        for(int i=0;i<a.size()-1;i++){
             if(a[i]>a[i+1]){
                de=1;
                in++;
             }
             else if(a[i]<a[i+1]){
                de++;
                in=1;
             }
             else{
                de=1;
                in=1;
             }
             ans = max({ans,in,de});
        }
    return ans;
    }
};