class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==2 || n==1) return n;
        int log = log2(n);
        log++;
     return 1<<log;   
    }
};