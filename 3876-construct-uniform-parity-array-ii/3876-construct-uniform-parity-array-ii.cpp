class Solution {
public:
 bool sol(vector<int>& nums1){
     set<int> odd;
       vector<int> a = nums1;
       int n = a.size();
       for(int i =0 ; i<n ; i++) if(a[i]%2==1)  odd.insert(a[i]); 
       bool ok = true;
       for(int i=0;i<n;i++)
        if(a[i]%2 == 1) {
           auto it = odd.lower_bound(nums1[i] - 1);
                if(it == odd.begin()) {
                    ok = false;
                    break;
                }
       }
       if(ok) return true;
       ok = true;
       for(int i=0;i<n;i++)
        if(a[i]%2==0){
              auto it = odd.lower_bound(nums1[i]);
                if(it == odd.begin()) {
                    ok = false;
                    break;
                }
        }

        return ok;
 }
    bool uniformArray(vector<int>& nums1) {
      int mn = *min_element(begin(nums1),end(nums1));
      if(mn%2==1) return true;
      for(int x : nums1) if(x%2==1) return false;
      return true;
    }
};