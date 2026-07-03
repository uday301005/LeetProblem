class Solution {
public:
typedef pair<long long, int> P;
unordered_map<int, vector<pair<int,long long>>> adj;
int n;
long long K;
bool check(int val){
      vector<long long> res(n,LLONG_MAX);
      priority_queue<P, vector<P>, greater<P>> pq;
      res[0]=0;
      pq.push({0,0});
      while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d>K) return false;
        if(u==n-1) return true;
        if(d > res[u]) continue;
        for(auto [v,c]:adj[u]){
            if(c<val) continue;
            if(d+c<res[v]){
                res[v] = d+c;
                pq.push({d+c,v});
            }
        }
      }
      return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        long long l = LLONG_MAX, r = LLONG_MIN;
        K=k;
        n=online.size();
        for(auto & a : edges){
            int  u = a[0] , v = a[1];
            long long c= a[2];
            if(!online[u] || !online[v]) continue;
              l =  min(l,c);
              r =  max(r,c);
            adj[u].push_back({v,c});
        }
        int ans = -1;
        while(l<=r){
           long long mid = l+(r-l)/2;
           if(check(mid)){
            l=mid+1;
            ans = mid;
           }
           else
           r=mid-1;
        }
     return ans;

    }
};