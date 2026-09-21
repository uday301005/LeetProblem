class Solution {
public:
    vector<long long> resultArray(vector<int>& a, int k) {
        vector<long long> res(k,0),prev(k,0);
        int n=a.size();
        for(int i=0;i<n;i++){
            vector<long long> curr(k,0);
         int currE = a[i]%k;
         curr[currE]++;
         for(int old =0 ;old<k;old++){
            int ne = ((long long)old*a[i]%k)%k;
            curr[ne] += prev[(int)old];
         }
         prev = move(curr);
         for(int x=0;x<k;x++)
         res[x] += prev[x];
         }
         return res;
    }
};