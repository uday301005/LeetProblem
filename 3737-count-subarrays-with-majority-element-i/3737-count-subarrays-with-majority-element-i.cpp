class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int t) {
        int n = a.size();
        vector<long long> pre(2*n+1,0);
        pre[n] = 1;
        int cnt =n;
        long long  ans =0,presum=0;
          for(int i=0;i<n;i++){
             if(a[i] == t){
               presum += pre[cnt];
               ++cnt;
               ++pre[cnt];
             }
             else{
               --cnt;
               presum -= pre[cnt];
               ++pre[cnt];
             }
              ans += presum;
          }        
    return (int)ans;
    }
};