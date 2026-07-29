class Solution {
public:
long long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        //5C3 == 5C2
        //5C2 == 5C(5-2) = 5C3
        r = min(r, n-r); //nCr == nC(n-r)

        long long result = 1;

        for(int i = 1; i <= r; i++) {//O(log2(k))
            result = result * (n - r + i)/i; //result is becoming twice

            if(result >= k) 
                return k;
        }

        return result;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i=0;i<n/2;i++)
         freq[s[i]-'a']++;
        char mid = '0';
        if(n%2==1) mid = s[n/2];
      
      string res;

      for(int i=0;i<n/2;i++){
         bool place = false;

         for(int j=0;j<26;j++){
            if(freq[j]>0){
                freq[j]--;

                long long ways = 1;
                int letters = 0;
                for(int c=0;c<26;c++) letters += freq[c];

                for(int c=0;c<26;c++){
                    if(freq[c]>0){
                        ways *= nCr(letters,freq[c],k);
                        letters -= freq[c];
                    }

                    if(ways >= k) break;

                }
                if(ways>=k){
                    res.push_back(j+'a');
                    place = true;
                    break;
                }

                k -= ways;
               freq[j] += 1;

            }
         }
         if(!place) return "";
      }
      string rev = res;
      reverse(rev.begin(),rev.end());
      if(mid != '0')   res.push_back(mid);
       return res+rev;
    }
};