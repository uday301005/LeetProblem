class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(auto & a : nums)
            if(a>0) st.insert(a);
        if(st.empty()) return 1;
        int pre=0;
        for(auto it = st.begin(); it != st.end(); it++){
            int val = *it;
         if(val>pre+1) return pre+1;
         pre = val;
                  }
return *prev(st.end())+1;
    }
};