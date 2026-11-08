class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        int c=0,n=a.size(),m=a[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           if(a[i][j]==1){
            row[i]++;
            col[j]++;
            c++;
           }
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         if(a[i][j]==1)
          if(row[i]==1 && col[j]==1)
           c--;

        return c;
    }
};