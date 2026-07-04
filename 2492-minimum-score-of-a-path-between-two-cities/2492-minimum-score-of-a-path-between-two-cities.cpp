class Solution {
public:
 vector<int> parent;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[a] = b;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
         for(auto &e : roads)    unite(e[0], e[1]);

         int p = find(1);
         
        int ans = INT_MAX;
        for(auto &e : roads) {
            if(find(e[0]) == p) {
                ans = min(ans, e[2]);
            }
        }
        return ans;
    }
};