class Solution {
public:
int mod=1e9+7;
vector<vector<int>> PT;
int solve(vector<int> a){
    int n=a.size();
    if(n<3) return 1;
    int root = a[0];
    vector<int> left,right;
    for(int x: a) 
    if(x<root) left.push_back(x);
    else if(x>root) right.push_back(x);
    int x = solve(left);
    int y = solve(right);
    int z = PT[n-1][left.size()];
     return (1LL * x * y % mod * z) % mod;
}
    int numOfWays(vector<int>& nums) {

      int n=nums.size();
      PT.resize(n+1);
      for(int i=0;i<=n;i++){
        PT[i] = vector<int>(i+1,1);

        for(int j=1;j<i;j++){
            PT[i][j] = (PT[i-1][j-1]+PT[i-1][j])%mod;
        }
      }

        return solve(nums)-1;
    }
};