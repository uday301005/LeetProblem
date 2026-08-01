class Solution {
public:
int dp[30][30];
int solve(vector<int> & a, int i,int j){
   
   if(i>j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
 int ti = a[i] + min( solve(a,i+2,j),solve(a,i+1,j-1) );
 int tj = a[j] + min(solve(a,i,j-2), solve(a,i+1,j-1) );
 return dp[i][j] = max(ti,tj);   

}
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
       int full = accumulate(begin(nums),end(nums),0);
       memset(dp,-1,sizeof(dp));
       int p1 =  solve(nums,0,n-1);
       return 2*p1 >= full;
    }
};