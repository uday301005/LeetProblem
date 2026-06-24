class Solution {
public:
typedef vector<vector<int>> Mat;
Mat Mul(const Mat & A ,const Mat & B){
   Mat C(2,vector<int>(2,0));
   for(int i=0;i<2;i++)
     for(int j=0;j<2;j++)
      for(int k=0;k<2;k++)
       C[i][j] += A[i][k]*B[k][j];
    return C;
}
Mat Pow(const Mat & base,int exp){
    if(exp==0){
        Mat id(2,vector<int>(2,0));
        id[0][0]=1;
        id[1][1]=1;
        return id;
    }
   Mat half = Pow(base,exp/2);
   Mat res = Mul(half,half);
   if(exp%2==1) res = Mul(res,base);
   return res;
}
    int fib(int n) {
        if(n==0) return 0;
        Mat T = {{1,1},{1,0}};
        Mat Tn = Pow(T,n-1);
        return Tn[0][0];

    }
};