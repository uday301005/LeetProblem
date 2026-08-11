class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        int sum = a[0];
        unordered_set<int> st;
        for(int x : a) st.insert(x);
        for(int j=1;j<n;j++)
            if(a[j-1]+1 == a[j]){
                sum += a[j];
            }
            else break;
        while(st.count(sum))
        sum++;

        return sum;
    }
};