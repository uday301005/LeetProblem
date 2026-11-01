class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums),end(nums),0) - nums.size()*(*min_element(begin(nums),end(nums)));
        sort(nums.begin(),nums.end());
        int mn = nums[0],ans=0;
        for(int a : nums){
            ans += a-mn;
        }
        return ans;
    }
};