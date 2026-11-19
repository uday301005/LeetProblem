class Solution {
public:
    int minimizeSum(vector<int>& a) {
        int n=a.size();
    sort(a.begin(),a.end());
      return min({a[n-3]-a[0],a[n-1]-a[2],a[n-2]-a[1]});

    }
};