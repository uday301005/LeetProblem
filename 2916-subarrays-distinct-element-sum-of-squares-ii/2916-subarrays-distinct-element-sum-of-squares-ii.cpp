class Solution {
public:
int n,mod=1e9+7;
vector<long long> segSum,seg,lazy;

// void lazyAddition(int i, int l, int r, int val) {
//         int len = (r-l+1);
//         segSum[i] += 2*val*segSum[i] + len * val * val;
//         segSum[i] += (len * val);
//     }
void lazyAddition(int i, int l, int r, int val) {
    long long len = r - l + 1;
    long long oldSum = seg[i];

    segSum[i] = (segSum[i] + 2LL * val * oldSum + len * val * val) % mod;

    seg[i] = (seg[i] + len * val) % mod;
}
void update(int i, int l,int r, int st, int end,int val){
  if(lazy[i]!=0){
     lazyAddition(i, l, r, lazy[i]);
    if(l!=r){
        lazy[2*i+1] += lazy[i];
    lazy[2*i+2] += lazy[i]; 
    }
    lazy[i]=0;
  }
 if(end<l || r < st || l>r) return;
 if(st<=l && r<=end){
    lazyAddition(i, l, r, val);
    if(l!=r){
    lazy[2*i+1] += val;
    lazy[2*i+2] += val;}
    return;
 }
 int mid = l+(r-l)/2;
 update(2*i+1,l,mid,st,end,val);
 update(2*i+2,mid+1,r,st,end,val);
 seg[i] = seg[2*i+1]+seg[2*i+2];
 segSum[i] = segSum[2*i+1]+segSum[2*i+2];
 
}
    int sumCounts(vector<int>& a) {
        long long res=0;
        n = a.size();
        seg.resize(4*n,0);
        segSum.resize(4*n,0);
        lazy.resize(4*n,0);
        vector<int> last(1e5+1,-1);
        for(int i=0;i<n;i++){
          int st=last[a[i]]+1,end=i;
          update(0,0,n-1,st,end,1);
          res =(res+segSum[0])%mod;
          last[a[i]]= i;
        }
return res;
    }
};