class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = 0,mn = 1000;
        for(auto x : nums) {
        mx = max(mx,x);
        mn = min(mn,x);}
        return gcd(mx,mn);
    }
};