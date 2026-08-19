class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_set<int> st;
        
        sort(begin(res),end(res));
        int m= res.size();
        int i=m-1,j=m-1,ans=0;
        while(i>=0){
            vector<int> a(11,0);
            st.insert(res[i][0]);
               while(j>=0 && res[i][0] == res[j][0] ) {
                int k = res[j][1];
                a[k] = -1;
                j--;}
            for(int i=1;i<11;i++) a[i] += a[i-1];
       
       if(a[5] == a[1] && a[9] == a[5] ) ans += 2;
    else if(a[5] == a[1] || a[7] == a[3] ||  a[9] == a[5] ) ans++;
         i=j;
        }
      int use = st.size();
      int rem = n-use;
      ans += 2*rem;

    return ans;
    }
};