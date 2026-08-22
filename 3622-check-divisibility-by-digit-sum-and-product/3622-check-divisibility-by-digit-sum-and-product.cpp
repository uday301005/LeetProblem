class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro= 1;
        int temp = n;
        while(temp){
            int rem = temp%10;
            sum += rem;
            pro *= rem;
            temp /=10;
        }
        return n%(sum+pro) == 0;
    }
};