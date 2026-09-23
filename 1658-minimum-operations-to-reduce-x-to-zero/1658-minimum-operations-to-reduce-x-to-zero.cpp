class Solution {
public:
    int minOperations(vector<int>& a, int target) {
      int end=0,st=0,n=a.size();
      long long all = accumulate(a.begin(),a.end(),0LL);
      target = all-target;
        int ans=-1;
        long long sum=0;
        while(true){
             if(target>=sum){
                if(end<n){
                    sum += a[end];
                   end++;
                }
             else break;
             }
             else{
                if(st<end){
                 sum -= a[st];
                st++;
                }
              else break;
             }
             if(target==sum)
             ans= max(ans,end-st);
        }
         return  ans!=-1?n-ans:-1;   
    }
};