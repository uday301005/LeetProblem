class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int N = n+2*(n-1);
        vector<vector<int>> a(N,vector<int>(N,0));
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            a[i+n-1][j+n-1] = img1[i][j];
        int ans = 0;
        for(int i=0;i<=N-n;i++)
         for(int j=0;j<=N-n;j++){
            int k=0;
           for(int r=0;r<n;r++)
            for(int c=0;c<n;c++)
             if(img2[r][c] == 1 && a[r+i][c+j] ==1) k++;
               ans = max(ans,k);
               }
   return ans;
    }

};