class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        vector<int> res,a1,a2;
        a1.push_back(a[0]);
        a2.push_back(a[1]);
       for(int i=2;i<a.size();i++)
        if(a1.back() > a2.back()) a1.push_back(a[i]);
        else a2.push_back(a[i]);
       for(int x: a1) res.push_back(x);
       for(int x: a2) res.push_back(x);
        return res;
    }
};