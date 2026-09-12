class Solution {
public:
int n;
vector<int> next;
struct node {
    long long score = -1;
    vector<int> idx;
};
vector<vector<node>> dp;
node solve(vector<vector<int>>& a,int i,int k){
    if(k==0 || i==n)
    return node();
     if (dp[i][k].score != -1)
            return dp[i][k];
    node skip = solve(a,i+1,k);
    node take = solve(a,next[i],k-1);

    node ans;
    ans.score = a[i][2]+take.score;
    ans.idx = take.idx;
    ans.idx.push_back(a[i][3]);
     sort(begin(ans.idx),end(ans.idx));

    if(skip.score>ans.score) return dp[i][k] = skip;
    else if(skip.score<ans.score) return dp[i][k] = ans;
  
  return dp[i][k]= ((skip.idx < ans.idx) ? skip : ans);
    
}
    vector<int> maximumWeight(vector<vector<int>>& a) {
        n = a.size();
        next.resize(n);
              int K=4;
        dp.resize(n+1,vector<node>(K+1));
        for(int i=0;i<n;i++)
         a[i].push_back(i);
        sort(begin(a),end(a));
         
        for(int i=0;i<n;i++){
            int val = a[i][1],x=n;
            int l = 0,r=n-1;
            while(l<=r){
                int mid = l +(r-l)/2;
                if(a[mid][0] > val){
                   x = mid;
                   r= mid-1;
                }
                else l = mid+1;
            }
            next[i] = x;
        }
        for(int i=n-1; i>=0; i--){
            int wt = a[i][2];
            int og = a[i][3];
            int j = next[i];
            for(int k=1;k<=K;k++){
               node temp =  dp[j][k-1],skip=dp[i+1][k],take,res; 
               take.score = wt+temp.score;
               take.idx = temp.idx;
               take.idx.push_back(og);
               sort(begin(take.idx),end(take.idx));
               if(take.score<skip.score) res = skip;
               else if(take.score>skip.score) res = take;
               else res = (take.idx<skip.idx ? take : skip);
               
               dp[i][k] = res;
            }
        }
  return dp[0][4].idx;
    }
};