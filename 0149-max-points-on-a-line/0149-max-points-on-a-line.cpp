class Solution {
public:
    int maxPoints(vector<vector<int>>& a) {
        int n = a.size(),res=0;
        
        for (int i = 0; i < n - 1; i++) {
            unordered_map<double, int> mp;
            int same=0,vertical=0;
            int x1 = a[i][0], y1 = a[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = a[j][0], y2 = a[j][1];
                if (x2 == x1 && y1==y2) same++;
                else if (x2 == x1) vertical++;
                else{
                  double  dis = (y2 - y1) / (double)(x2 - x1);
                    mp[dis]++;
                    }
            }
            int maxi =vertical;
           for (auto& p : mp)
           maxi = max(maxi, p.second+same);
        
     res = max(res,maxi);
        }
        return res+1;
    }
};