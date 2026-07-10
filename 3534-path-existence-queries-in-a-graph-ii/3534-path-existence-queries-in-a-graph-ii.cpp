class Solution {
public:
int roe,col;
vector<vector<int>> mat;
 int custom(vector<pair<int, int>>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(arr[mid].first <= target) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& a, int maxDiff, vector<vector<int>>& queries) {
        int col = log2(n) + 1;
        int row = n;

       vector<pair<int,int>> vp;
          vector<int> res,f(n);

       mat.resize(n,vector<int>(col));

        for(int i=0;i<n;i++)  vp.push_back({a[i],i});
       sort(begin(vp),end(vp));
         for(int i=0;i<n;i++) f[vp[i].second] = i;

       for(int i=0;i<n;i++) mat[i][0] = custom(vp, vp[i].first + maxDiff);

       for(int j=1 ; j<col; j++)
          for(int i=0;i<n;i++)
             mat[i][j] = mat[ mat[i][j-1] ][j-1];
      
        for(auto & q : queries){
            int u = q[0] , v = q[1];
            int x = f[u] , y = f[v];
            if(x==y) {res.push_back(0);
            continue;}
            if(x > y) swap(x, y);

            int cur=x,ans=0;
            for(int j = col-1; j >= 0; j--)
              if(mat[cur][j] < y ){
               cur = mat[cur][j];
               ans += (1 << j);
              }
    if(mat[cur][0] >= y ) res.push_back(ans+1);
    else res.push_back(-1);
        }
return res;
    }
};