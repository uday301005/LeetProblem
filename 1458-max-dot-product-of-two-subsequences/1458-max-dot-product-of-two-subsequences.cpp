class Solution {
public:
int n,m;
vector<int> a,b;
vector<vector<int>> dp;
  int solve(int i,int j){
      if(i>=n || j>=m) return -1e9;
      if(dp[i][j] != -1) return dp[i][j];
      int val = a[i]*b[j];
    int take = val + solve(i+1,j+1);
    int takei =  solve(i,j+1);
    int takej = solve(i+1,j);
return dp[i][j] = max({val,take,takei,takej});
  }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
       a=nums1;
       b=nums2;
       n=a.size();
       m=b.size();
       dp.resize(n+1,vector<int>(m+1,-1));
       for(int i=n;i>=0;i--)
        for(int j =m;j>=0;j--)
            if(i==n || j==m) dp[i][j]=-1e9;
            else{
                int val = a[i]*b[j];
                dp[i][j] = max({val,val+dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
            }
        
       return  dp[0][0];
    }
};