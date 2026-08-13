class Solution {
public:
struct Node {
  int maxlen=0;
  int pre=0;
  int suff=0;
  char leftch;
  char rightch;
};
int n;
string a;
vector<Node> seg;

void func(int i,int leftLen, int rightLen){
     seg[i].leftch = seg[2*i+1].leftch;
     seg[i].rightch = seg[2*i+2].rightch;

     seg[i].pre = seg[2*i+1].pre;
      if (seg[2*i+1].pre == leftLen && seg[2*i+1].rightch == seg[2*i+2].leftch) {
            seg[i].pre = seg[2*i+1].pre + seg[2*i+2].pre;
        }
     seg[i].suff = seg[2*i+2].suff;
     
     if (seg[2*i+2].suff == rightLen && seg[2*i+1].rightch == seg[2*i+2].leftch) {
             seg[i].suff = seg[2*i+1].suff + seg[2*i+2].suff;
        }
     int x = (seg[2*i+1].rightch == seg[2*i+2].leftch) ? seg[2*i+1].suff + seg[2*i+2].pre  : 0;
     seg[i].maxlen = max({x,seg[2*i+1].maxlen,seg[2*i+2].maxlen});
}

void build(int i, int l, int r){
    if(l==r){
      seg[i].maxlen = 1;
      seg[i].pre = 1;
      seg[i].suff  = 1;
      seg[i].leftch = a[l];
      seg[i].rightch = a[r];
      return;
     }
     int mid = l + (r-l)/2;

     build(2*i+1,l,mid);
     build(2*i+2,mid+1,r);

   func(i,mid-l+1 , r-mid);
}

void update(int i, int l, int r, int idx ,char val){
    if(l==r){
       seg[i] = { 1, 1, 1, val, val };
        return ; 
    }
    int mid = l +(r-l)/2;
    if(idx <= mid)
    update(2*i+1 , l, mid , idx , val);
    else
    update(2*i+2 , mid+1 , r ,idx ,val);
    func(i,mid-l+1 , r-mid);
}
// int query(int i ,int l ,int r , int st ,int r)

    vector<int> longestRepeating(string k, string que, vector<int>& idx) {
        n= k.size();
        a = k;
        seg.resize(4*n);
     vector<int> res;
   build(0,0,n-1);
     for(int i=0;i<que.size();i++){
       update(0,0,n-1,idx[i],que[i]);
         res.push_back(seg[0].maxlen);
     }
     return res;
    }
};