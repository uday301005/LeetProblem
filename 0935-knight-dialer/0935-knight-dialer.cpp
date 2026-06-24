class Solution {
public:
typedef vector<vector<long long>> Mat;
int mod=1e9+7;
Mat Mul(const Mat & A,const Mat & B){
    int r = A.size(),c=B[0].size(),mid=B.size();
    Mat C(r,vector<long long>(c,0));
    for(int i=0;i<r;i++)
     for(int j=0;j<c;j++)
     for(int k=0;k<mid;k++)
     C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
     return C;
}
Mat Pow(const Mat & base,int exp){
       int r = base.size(),c=base[0].size();
    if(exp==0) {
        Mat id(r,vector<long long>(c,0));
    for(int i=0;i<min(r,c);i++) id[i][i] = 1;
    return id;
    }
    Mat half = Pow(base,exp/2);
    Mat res = Mul(half,half);
    if(exp%2==1) res = Mul(res,base);
    return res;
}
    int knightDialer(int n) {
       Mat T = {
    //0 1 2 3 4 5 6 7 8 9   (previous digit j)
    {0,0,0,0,1,0,1,0,0,0}, // 0
    {0,0,0,0,0,0,1,0,1,0}, // 1
    {0,0,0,0,0,0,0,1,0,1}, // 2
    {0,0,0,0,1,0,0,0,1,0}, // 3
    {1,0,0,1,0,0,0,0,0,1}, // 4
    {0,0,0,0,0,0,0,0,0,0}, // 5
    {1,1,0,0,0,0,0,1,0,0}, // 6
    {0,0,1,0,0,0,1,0,0,0}, // 7
    {0,1,0,1,0,0,0,0,0,0}, // 8
    {0,0,1,0,1,0,0,0,0,0}  // 9
};
        Mat Tn = Pow(T,n-1);
      Mat base(10, vector<long long>(1,1));
        Mat res = Mul(Tn,base);
        long long ans = 0;
for(int i = 0; i < 10; i++){
    ans = (ans + res[i][0]) % mod;
}
return ans;
        return ans;
    }
};