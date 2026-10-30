class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string a, int k) {
        vector<vector<pair<int,int>>> adj(n);
          for(auto edge : edges){
            int u = edge[0], v = edge[1], w= edge[2];
            adj[u].push_back({v,w});
          }
    priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> pq;
    vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
     dist[0][1] =0;
     pq.push({0,0,1});
     while(!pq.empty()){
        auto [d,u,c] = pq.top();
        pq.pop();
        if (d != dist[u][c]) continue;
      for (auto [v, w] : adj[u]) {
                int nc = (a[u] == a[v]) ? c + 1 : 1;
                if (nc > k) continue;
                if (dist[v][nc] > d + w) {
                    dist[v][nc] = d + w;
                    pq.push({d + w, v, nc});
                }
            }
     }
      int ans = *min_element(dist[n-1].begin(), dist[n-1].end());
        return ans == INT_MAX ? -1 : ans;
    }
};