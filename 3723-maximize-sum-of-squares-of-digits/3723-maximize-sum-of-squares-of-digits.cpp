class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
       int c = sum/9;
       int r = sum%9;
       res += string(c,'9');
       if(r!=0)
       res += r+'0';
       int rem = num-res.size();
       if(rem>=0)
       res += string(rem,'0');
       else res= "";
       return res;
    }
};