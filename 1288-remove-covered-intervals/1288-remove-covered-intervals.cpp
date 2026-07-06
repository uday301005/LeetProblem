class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
          sort(a.begin(),a.end(),[](vector<int> &A , vector<int> & B){
            if(A[0] == B[0]) return B[1]<A[1];
          return A[0]<B[0];
            });
       int n=a.size();
       int rem =0,mx=0;
       for(int i=0;i<n;i++){
           if(a[i][1]>mx){
             rem++;
           mx = a[i][1];
           }
       }
  return rem;
    }
};