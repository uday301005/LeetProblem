class Solution {
public:
    int  n,m;
    bool check(vector<vector<int>> & mat , int k){
      vector<int> row(n,0),col(m,0);
        for(int i=0;i+k<=n;i++)
            for(int j=0;j+k<=m;j++){
                int sum = mat[i+k-1][j+k-1];
                if(i>0) sum -= mat[i-1][j+k-1];
                if(j>0) sum -= mat[i+k-1][j-1];
                if(i>0 && j>0) sum += mat[i-1][j-1];
                if(sum == k*k){
                    row[i] = 1;
                    col[j] = 1;                
                }
            }
        for(int i = 1; i < n; i++)
        row[i] += row[i-1];
    for(int j = 1; j < m; j++)
        col[j] += col[j-1];
        for(int i=0;i+k<=n;i++)
            for(int j=0;j+k<=m;j++){
                int sum = mat[i+k-1][j+k-1];
                if(i>0) sum -= mat[i-1][j+k-1];
                if(j>0) sum -= mat[i+k-1][j-1];
                if(i>0 && j>0) sum += mat[i-1][j-1];
                if(sum != k*k)continue;

                if(i>=k && row[i-k] >0) return true;
                if(j>=k && col[j-k] >0) return true;
                
            }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        for(int i=0;i<n;i++)
            for(int j =1;j<m;j++)
                mat[i][j] += mat[i][j-1];
       
        for(int j =0;j<m;j++)
            for(int i=1;i<n;i++)
                mat[i][j] += mat[i-1][j];

        int  st = 1,end = min(n,m),k=0 ;
        while(st<=end){
            int  mid = st + (end-st)/2;
            if(check(mat,mid)){
                k=mid;
                st = mid + 1;
            }
            else 
                end = mid -1;
        }
         return k*k;
    }
};