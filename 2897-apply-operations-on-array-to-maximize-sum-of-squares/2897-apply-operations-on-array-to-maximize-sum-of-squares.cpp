class Solution {
public:
    int maxSum(vector<int>& a, int k) {\
        vector<int> bit(32,0);
       for(int x :a)
        for(int j=0;j<32;j++)
         if(x &(1<<j))
           bit[j]++;
   long long sum =0;
   int mod = 1e9+7;
      while(k--){
        long long num=0;
        for(int i=0;i<32;i++)
          if(bit[i]>0){
            bit[i]--;
            num+= (1<<i);
          }
          sum = (sum + num*num)%mod;
      }
return sum;
    }
};