class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size();
    sort(begin(a),end(a));
     int ans = 0;
     for(int x : a)
     ans += abs(x-a[n/2]);
return ans;
    }
};