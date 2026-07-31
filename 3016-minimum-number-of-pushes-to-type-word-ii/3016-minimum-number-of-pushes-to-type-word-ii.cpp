class Solution {
public:
    int minimumPushes(string word) {
         int res=0,n=word.size();

         vector<int> freq(26,0);
         for(int i=0;i<n;i++)
          freq[ word[i] -'a' ]++;
         sort(freq.begin(),freq.end(),greater());

         for(int i=0;i<8;i++)
          res += freq[i];
         for(int i=8;i<16;i++)
        res += 2*freq[i];
         for(int i=16;i<24;i++)
          res += 3*freq[i];
  res += 4*(freq[24] + freq[25]);
        return res;
    }
};