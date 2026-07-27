class Solution {
public:
unordered_map<int,vector<int> > left,right;
    int minimumDifference(vector<int>& a) {
        int N = a.size();
        int n = N/2 , S = accumulate(begin(a),end(a),0);

        for(int mask =0; mask < (1<<n); mask++){
           int s=0;
           int c=0;
            
            for(int i=0;i<n;i++ )
                if(mask & (1 << i)){
                    s += a[i];
                    c++;
                }
            left[c].push_back(s);
        }
        for(int mask =0; mask < (1<<n); mask++){
           int s=0;
           int c=0;
            
            for(int i=0;i<n;i++ )
                if(mask & (1 << i)){
                    s += a[n+i];
                    c++;
                }
            right[c].push_back(s);
        }
        for(int c=0;c<=n;c++)
         sort(begin(right[c]) ,end(right[c]));

        int ans = INT_MAX;
        for(int k = 0; k<=n; k++){
            int m = n-k;
            for(int l : left[k]){
                int need = (S-2*l)/2;

                int low = lower_bound(begin(right[m]), end(right[m]), need) - begin(right[m]);

                if(low < right[m].size()){
                    int r = right[m][low];
                    ans = min(ans,abs(S-   2*(l+r)  )  );
                }
                if(low-1 >= 0){
                     int r = right[m][low-1];
                    ans = min(ans,abs(S-   2*(l+r)  )  );
                }

            }
        }
return ans;

    }
};