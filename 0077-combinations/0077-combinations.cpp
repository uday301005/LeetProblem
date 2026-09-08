class Solution {
public:
   vector<vector<int>> res;
   int  n,k;
   void solve(int i,vector<int> & curr){
       if(curr.size() == k) {
        res.push_back(curr);
        return ;
       }
     if(i<=n){
     solve(i+1,curr);
     
      curr.push_back(i);
      solve(i+1,curr);
       curr.pop_back();}
   }
    vector<vector<int>> combine(int ne, int ke) {
        n = ne;
        k= ke;
        vector<int> curr;
        solve(1,curr);
        return res;
    }
};