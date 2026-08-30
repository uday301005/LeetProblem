class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int mx=INT_MIN,mn=INT_MAX,imn = -1 , imx=-1,n=a.size();
        for(int i=0;i<n;i++){
            if(a[i] > mx){
                mx=a[i];
                imx=i;
            }
            if(a[i] < mn){
                mn = a[i];
                imn = i;
            }
        }
        int ans = 2*n;
        if(imn<imx){
            ans = min(ans, imx+1);
            ans = min(ans, n-imn);
            ans = min(ans, imn+1 + n-imx);
        }
        else if(imn>imx){
            ans = min(ans, imn+1);
            ans = min(ans, n-imx);
            ans = min(ans, imx+1 + n-imn);
        }
        else ans = 1;
        return ans;
    }
};