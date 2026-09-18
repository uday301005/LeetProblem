class Solution {
public:
    int mod = 1e9 + 7;
    long long ans = 0;
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> mul = {
        {2, {2}},      {3, {3}},   {5, {5}},       {6, {2, 3}},   {7, {7}},
        {10, {2, 5}},  {11, {11}}, {13, {13}},     {14, {2, 7}},  {15, {3, 5}},
        {17, {17}},    {19, {19}}, {21, {3, 7}},   {22, {2, 11}}, {23, {23}},
        {26, {2, 13}}, {29, {29}}, {30, {2, 3, 5}}};
    vector<int> a;
    int n;
   void solve(int i, unordered_set<int>& st, long long ways) {
    if (i == n) {
        if(!st.empty())
        ans = (ans+ways)%mod;
        return;
    }
    // skip
    solve(i + 1, st, ways);
    bool ok = true;
    for (int p : mul[a[i]]) {
        if (st.count(p)) {
            ok = false;
            break;
        }
    }
    if (ok) {
        for (int p : mul[a[i]])
            st.insert(p);
        solve(i + 1,st, ways * mp[a[i]] % mod);
        for (int p : mul[a[i]])
            st.erase(p);
    }
}
    int numberOfGoodSubsets(vector<int>& nums) {
        unordered_set<int> st = {1, 4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
        int one=0;
        for (int x : nums) {
    if (x == 1)
        one++;
    else if (!st.count(x))
        mp[x]++;
}
        for (auto [x, y] : mp)    a.push_back(x);
        n = a.size();
        st.clear();
        solve(0, st,1);
        long long p = 1;
     for (int i = 0; i < one; i++)
     p = p * 2 % mod;
     ans = ans * p % mod;
        return ans;
    }
};