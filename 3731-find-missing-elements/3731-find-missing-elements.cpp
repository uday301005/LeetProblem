class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        vector<int> res;
        int mx = *max_element(begin(a),end(a));
        int mn = *min_element(begin(a),end(a));

       unordered_set<int> st;
       for(int & x : a) st.insert(x);
        for(int x = mn; x <= mx ; x++)
          if(!st.count(x))
           res.push_back(x);

        sort(begin(a),end(a));
        return res;
    }
};