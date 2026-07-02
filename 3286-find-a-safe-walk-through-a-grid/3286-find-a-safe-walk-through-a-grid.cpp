class Solution {
public:
int n,m;
int d[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
 int solve(vector<vector<int>>& a, int i,int j,vector<vector<bool>> & vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return INT_MAX; 
            if(i==n-1 && j==m-1)    return a[i][j];


           vis[i][j] = true;
      int sum =INT_MAX;
       for(int k=0;k<4;k++){
        int i_=i+d[i][0], j_ = j + d[i][1];
         int next = solve(a,i_,j_,vis);
       if(next != INT_MAX){
    sum = min(sum , a[i][j] + next);
              }
       }
       vis[i][j] = false;
        return sum;
    }
bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> best(n,vector<int>(m,-1));
        priority_queue<tuple<int,int,int>> pq;
        int startHealth = health - grid[0][0];
        if(startHealth <= 0) return false;
        pq.push({startHealth,0,0});

        while(!pq.empty()){
            auto [h,i,j] = pq.top();
            pq.pop();
             if(i == n-1 && j == m-1) return true;
            if(h < best[i][j]) continue;
           
            if(h < best[i][j]) continue;

            for(int k=0;k<4;k++){
                int ni = i + d[k][0];
                int nj = j + d[k][1];

                if(ni<0 || nj<0 || ni>=n || nj>=m) continue;

                int nh = h - grid[ni][nj];
                if(nh <= 0) continue;

                if(best[ni][nj] >= nh) continue;

                best[ni][nj] = nh;
                pq.push({nh, ni, nj});
            }
        }


return false;
    }
};