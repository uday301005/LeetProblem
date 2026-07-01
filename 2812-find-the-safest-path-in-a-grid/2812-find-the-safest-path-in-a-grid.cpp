class Solution {
public:
    vector<vector<int>> a;
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
    bool solve(int i, int j, int sc, vector<vector<bool>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] < sc || vis[i][j])
            return false;
        if (i == n - 1 && j == n - 1)
            return true;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int i_ = i + d[k][0], j_ = j + d[k][1];
            if (solve(i_, j_, sc, vis))
                return true;
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& g) {
        n = g.size();
        a.resize(n, vector<int>(n, n + 1));
        int val = 0;
        queue<pair<int, int>> que;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == 1) {
                    que.push({i, j});
                    vis[i][j] = true;
                }

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto [r, c] = que.front();
                que.pop();
                a[r][c] = min(val, a[r][c]);
                for (int i = 0; i < 4; i++) {
                    int r_ = r + d[i][0];
                    int c_ = c + d[i][1];
                    if (r_ >= 0 && r_ < n && c_ >= 0 && c_ < n &&
                        !vis[r_][c_]) {
                        que.push({r_, c_});
                        vis[r_][c_] = true;
                    }
                }
            }
            val++;
        }
        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (solve(0, 0, mid, vis)) {
                l = mid + 1;
                ans = mid;
            } else 
                r = mid - 1;
        }
        return ans;
    }
};