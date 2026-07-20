class Solution {
public:
void rev(vector<int> & a,int l,int r){
    while(l<=r){
        swap(a[l],a[r]);
        l++;
        r--;
    }
}
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        int mod = n*m;
        k = k%mod;
        vector<int> res;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          res.push_back(a[i][j]);
        int l=0,r=n*m-1;
        rev(res,l,r);
        rev(res,l,k-1);
        rev(res,k,r);
        
      for(int i=0;i<res.size();i++)
       a[i/m][i%m] = res[i];

       return a;
    } 
};