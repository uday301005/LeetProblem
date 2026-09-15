class Solution {
public:
int n;
int solve(vector<int> & a ,int mid){
  long long ans = 0;
  for(int i=0;i<n;i++){
    ans += abs(mid-a[i]);
  }
  return  ans;
}
    int minMoves2(vector<int>& a) {
     n=a.size();
    sort(begin(a),end(a));
     int ans = 0;
     for(int x : a)
     ans += abs(x-a[n/2]);
      
return ans;
    }
};