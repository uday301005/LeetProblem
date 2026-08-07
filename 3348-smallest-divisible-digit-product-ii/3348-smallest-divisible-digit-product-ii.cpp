class Solution {
public:
string solve( long long t,int n){
   string res="";
   for(int d=9;d>=2;d--){
      while(t%d==0){
        res.push_back(d+'0');
        t /= d;
      }
   }
   while(res.size() < n)
    res.push_back('1');
    reverse(begin(res),end(res));
    return res;
}
    string smallestNumber(string num, long long t) {
         int n = num.length();
        long long temp = t;
        for(int primeFact : {2, 3, 5, 7}) 
            while(temp % primeFact == 0) 
                temp /= primeFact;
        if(temp != 1) 
            return "-1";

        vector<long long> remainingFactor(n+1, t);
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if(digit == 0) 
                break;
            remainingFactor[i+1] = remainingFactor[i]/gcd(remainingFactor[i], (long long)digit);
        }

        if(remainingFactor[n] == 1)    return num;
        
  int zeroPos = num.find('0');
        int zeroIdx = n-1;
        if(zeroPos != -1) 
            zeroIdx = zeroPos;

        for(int i = zeroIdx; i >= 0; i--) {
            long long  required = remainingFactor[i];
            int fs = n - 1 - i;
            for(int digit = (num[i] - '0')+1; digit <= 9; digit++) {
                long long fr = required / gcd(required, digit);
                string rn = solve(fr, fs);
                if(rn.length() == fs) 
                    return num.substr(0, i) + char(digit + '0') + rn;
            }
        }

        return solve(t, n+1);
    }
};