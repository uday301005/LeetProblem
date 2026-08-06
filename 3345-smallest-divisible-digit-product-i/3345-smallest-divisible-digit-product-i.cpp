class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num = n ;num<=100;num++){
            int res= 1;
         for(int temp = num ; temp>0 ;temp /= 10)
           res *= temp%10;
        if(res%t == 0) return num;
        }
        return -1;
    }
};