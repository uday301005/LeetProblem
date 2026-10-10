class Solution {
public:
    long long minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
        int n =  n1.size();
        long long k=k1+k2,ans=0;
        vector<int> freq(1e5+1,0);
        for(int i=0;i<n;i++)
       freq[abs(n1[i]-n2[i])]++;
  int next=0;
      for(int i=1e5;i>=0;i--){
    //   if(freq[i]==0) continue;
       freq[i] += next;
        if(freq[i]<k){
            next = freq[i];
            k-= freq[i];
            freq[i]=0;
           
        }
        else{
           next = k;
           freq[i] -= k;
           k=0;
           
        }
      }
      for(long long i=0;i<=1e5;i++)
        if(freq[i]>0)
     ans += 1LL * i * i * freq[i];
        return ans;
    }
};