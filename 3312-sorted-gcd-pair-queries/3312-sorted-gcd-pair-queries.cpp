class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
          int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));
        vector<int> div(maxVal+1, 0);
        for(int i = 0; i < n; i++) { 
            int num = nums[i];
            for(int j = 1; j*j <= num; j++) 
                if(num % j == 0) {
                    div[j]++;
                    if(num/j != j) 
                        div[num/j]++;   
                }  
        }

    vector<long long> pre(maxVal+1,0);
       for(int g = maxVal ; g>=1;g--){
    long long c = div[g];
    pre[g] = c*(c-1)/2;
       for(int i=2*g;i<=maxVal;i+=g)
          pre[g] -= pre[i];     
}
   for(int i=1;i<=maxVal;i++) pre[i] = pre[i]+pre[i-1];
      vector<int> result;
        for(long long idx : queries) { 
            int l = 1;
            int r = maxVal;
            int temp = 1;
            while(l <= r) {
                int mid_gcd = l + (r-l)/2;
                if(pre[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd-1;
                } else 
                    l = mid_gcd+1;
                
            }
            result.push_back(temp);
        }
        return result;


    }
};