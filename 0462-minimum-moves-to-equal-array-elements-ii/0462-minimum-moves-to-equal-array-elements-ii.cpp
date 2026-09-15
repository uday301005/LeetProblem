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

     int ans = INT_MAX;
     if(n%2==1){
        ans = min(ans,solve(a,a[n/2]));
       }
     else {
        ans = min(ans,solve(a, (a[n/2 - 1]+a[n/2] )/2) );
     }
return ans;
    }
};