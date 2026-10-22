class Solution {
public:
    int n;

    bool is(vector<int>& a, int idx, int inc) {
        if (inc > 0) {
            for (int i = idx; i < idx + n - 1; i++) {
                if (a[i] > a[i + 1])
                    return false;
            }
        } else {
            for (int i = idx; i > idx - n + 1; i--) {
                if (a[i] > a[i - 1])
                    return false;
            }
        }
        return true;
    }

    int minOperations(vector<int>& a) {
        n = a.size();
        vector<int> b = a;
        b.insert(b.end(), a.begin(), a.end());
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return -1;
        int ans=-1;
        if (is(b, idx, 1))
            ans = min(idx, n - idx + 2);
        else if (is(b, idx + n, -1))
            ans = 1+ min(idx+1, n - idx - 1);
        return ans;
    }
};