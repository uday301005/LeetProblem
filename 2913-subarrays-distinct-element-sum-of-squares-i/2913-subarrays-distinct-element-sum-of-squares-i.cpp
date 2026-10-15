class Solution {
public:
    int sumCounts(vector<int>& a) {
        int sum=0,n=a.size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(a[j]);
                int k = st.size();
                sum += k*k;
            }
        }
        return sum;
    }
};