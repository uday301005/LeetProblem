class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(),nums.end() ,greater());
        int m = 0,n=0;
        for(auto x : nums)
         if(x>m){
            n=m;
            m=x;
         }
         else if(x>n)
          n= x;
        return (m-1)*(n-1);
        return (nums[1]-1) * (nums[0]-1);
    }
};