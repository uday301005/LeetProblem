class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long res=0,i=0;
        while(n>0){
            int rem = n%10;
            if(rem!=0) {
                sum += rem;
            res += rem*pow(10,i);
              i++;
            }
            n/=10;
        }
return res*sum;  
    }
};