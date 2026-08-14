class Solution {
public:
    int maximumLengthSubstring(string s) {

        int ans = 0, st = 0, end = 0, n = s.size();
        unordered_map<char, int> mp;

        while (end < n) {

            mp[s[end]]++;
            end++;

            while (mp[s[end - 1]] > 2) {
                mp[s[st]]--;
                st++;
            }

            ans = max(ans, end - st);
        }

        return ans;
    }
};