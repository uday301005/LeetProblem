class Solution {
public:
vector<vector<pair<int,int>>> adj;
int n;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pass) {
        n = pass.size();
        adj.assign(n, {});
        for(auto & vec : edges){
            int u = vec[0] ,  v = vec[1] , w = vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        using T = tuple<int, int, int>;
         vector<vector<int>> dist(
            n, vector<int>(maxTime + 1, INT_MAX)
        );
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({pass[0],0,0});
        dist[0][0] =pass[0];
      while(!pq.empty()){
        auto [c,t,node] = pq.top();
        pq.pop();
        if(node==n-1) return c;
        if(c>dist[node][t]) continue;

       for(auto [nxt , rt] : adj[node]){
             int newD = c+pass[nxt];
             int nt = t+rt;
             if(nt<=maxTime && newD < dist[nxt][nt]){
                dist[nxt][nt] = newD;
                pq.push({newD,nt,nxt});
             }
       }
      }
       return -1;
    }
};