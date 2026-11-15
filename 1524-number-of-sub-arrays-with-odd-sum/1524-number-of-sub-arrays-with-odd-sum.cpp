class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        const int mod = 1e9 + 7;

        long long even = 1, odd = 0, ans = 0;
        int parity = 0;

        for (int x : a) {
            parity ^= (x & 1);

            if (parity == 1) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};