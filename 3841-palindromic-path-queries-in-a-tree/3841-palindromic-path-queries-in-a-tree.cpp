class Solution {
public:
vector<vector<int>> adj,ancestorTable;
int n,t=0,cols;
vector<int> tin,tout,euler,depth;
void dfs(int node,int parent, string & s,int d){
    depth[node]=d;
    ancestorTable[node][0] = parent;
   tin[node]=t;
   euler[t++] =  (1<<(s[node]-'a'));
   for(int & ch : adj[node])
     if(ch!=parent)
      dfs(ch,node,s,d+1);
   tout[node] = t;
   euler[t++] =  (1<<(s[node]-'a'));
}
  void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }
class segTree{
  vector<int> seg;
  int m;
  vector<int> a;
  int solve(int a,int b){
    return a^b;
  }
  public:
  segTree(vector<int> arr){
    a = arr;
    m = a.size();
    seg.resize(4*m,0);
    build(0,0,m-1);
  }
  void build(int i,int l,int r){
    if(l==r) {
        seg[i] = a[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    seg[i] = solve(seg[2*i+1],seg[2*i+2]);
      }
    void update(int i,int l,int r,int idx,int val){
        if(l==r){
            seg[i] = val;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid) update(2*i+1,l,mid,idx,val);
        else update(2*i+2,mid+1,r,idx,val);
        seg[i] = solve(seg[2*i+1],seg[2*i+2]);
    }
    int query(int i,int l,int r,int st,int end){
        if(l>r || end<l || r<st) return 0;
        if(st<=l && r<=end) return seg[i];
        int mid = l+(r-l)/2;
        return solve(query(2*i+1,l,mid,st,end),query(2*i+2,mid+1,r,st,end));
    }
};
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n=n;
        cols = log2(n)+1;
         ancestorTable.assign(n,vector<int>(cols,-1));
         depth.assign(n,0);
         adj.resize(n);
         tin.assign(n,0);
         tout.assign(n,0);
         euler.assign(2*n,0);
         for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
         }
          dfs(0,-1,s,0);
        segTree* seg = new segTree(euler);
        buildAncestorTable();
         vector<bool> res;
         for(string & qu : queries){
            stringstream ss(qu);
            string type;
            ss>>type;
            if(type=="update"){
                int idx ;
                char val ;
                ss>>idx>>val;
                s[idx]=val;
                int charVal = (1<<(val-'a'));
                seg->update(0,0,2*n-1,tin[idx],charVal);
                seg->update(0,0,2*n-1,tout[idx],charVal);
            }
            else{
                int u ,v;
                ss>>u>>v;
                int lca = getLCA(u,v);
                int val =(1<<(s[lca]-'a'));
                int mask = seg->query(0,0,2*n-1,0,tin[u]) ^ seg->query(0,0,2*n-1,0,tin[v]) ^ val;
              res.push_back((mask&(mask-1))==0);
            }
         }
         return res;
    }
};