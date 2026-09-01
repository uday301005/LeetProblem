class Solution {
public:
struct state {
  int r, c,e , collM;
};
    int minMoves(vector<string>& a, int energy) {
        int n = a.size(),m=a[0].size(),en = energy,pos=0,si=-1,sj=-1,ans=0;
        int dis[4][2] = { {-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> litter(n,vector<int>(m,-1));
         queue<state> que;
         for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            if(a[i][j] == 'S')  {
                si=i;
                sj=j;
            }
            else if(a[i][j] == 'L')
                   litter[i][j] = pos++;
         if(pos==0) return 0;

         int mx = (1<<pos) - 1 ;
         que.push({si,sj,en,0});
         long long total =
            1LL * n * m * (energy + 1) * (1 << pos);

        vector<char> vis(total, 0);

        auto id = [&](int r, int c, int e, int mask) {

            return ((((long long)r * m + c)
                     * (energy + 1) + e)
                     * (1 << pos)) + mask;
        };
       vis[id(si, sj, energy, 0)] = 1;
     while(!que.empty()){
          int size = que.size();
          while(size--){
            auto [r,c,e,collM] = que.front();
            que.pop();

            if(collM == mx) return ans;  
            if(e == 0) continue;
             for(auto & d : dis){
                int nr = r+d[0] , nc = c+d[1];
                if(nr>=0 && nr < n && nc >=0 && nc < m && a[nr][nc] != 'X' ){ 
                     int ne = e-1,nmask = collM;
                      if(a[nr][nc] == 'R') ne = energy;
                      else if(a[nr][nc] == 'L') nmask |= 1<<litter[nr][nc];

                        if (vis[id(nr, nc, ne, nmask)])
                        continue;
                        vis[id(nr, nc, ne, nmask)] = 1;
                      que.push({nr,nc,ne,nmask});
                }
             }
               
          }
          ans++;
     }
     return -1;
    }
};