class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        unordered_set<int> st;
        for(int x: a) st.insert(x);
        for(int i=k;i<=200;i+=k)
            if(!st.count(i)) return i;
        
        return k;
    }
};