class Solution {
public:
    const int mod = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;
    int s,m;
   Matrix MatMul(const Matrix & A, const Matrix & B) {
        Matrix  C(s,vector<long long>(s,0));
        for(int i=0;i<s;i++)
             for(int j=0;j<s;j++)
                 for(int k=0;k<s;k++) 
                       C[i][j] = (C[i][j] + A[i][k] * B[k][j] )%mod;
  return C;
    }
  Matrix MatPow(const Matrix & base, int expo){
      if(expo==0) {
        Matrix id(s, vector<long long>(s, 0));
          for(int i=0;i<s;i++) id[i][i] = 1;
          return id;
        }
        Matrix half = MatPow(base,expo/2);
        Matrix res = MatMul(half,half);
        if(expo%2==1) res = MatMul(res,base);
        return res;
  }

    int zigZagArrays(int n, int l, int r) {
     m = r-l+1;
     s = 2*m;
      Matrix T (s,vector<long long> (s,0));
      for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1; 
            }
        }
     Matrix power = MatPow(T,n-1);

     long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + power[i][j]) % mod;
            }
        }
        return (int) (total * 2 % mod);

     return 0;

    }
};