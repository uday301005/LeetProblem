class Solution {
public:
int n;
typedef long long ll; 
int MOD = 1e9+7;
 ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }
  
bool solve(vector<int>& a, int len,int base) {
    unordered_map<long long, int> mp;
    ll hash=0;
    long long  p = findPower(base, len-1); 
    
     int i = 0;
        int j = 0;
        while(j < n) { //O(n)
            hash = (hash * base + a[j]) % MOD;

            if(j-i+1 < len) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * a[i])%MOD + MOD) % MOD;

                i++;
                j++;
            }
        }
    for (auto & x : mp) {
        if (x.second == 1)
            return true;
    }
    return false;
}
    int smallestUniqueSubarray(vector<int>& a) {
         n=a.size();
          int base = *max_element(begin(a), end(a)) + 1;
        int l=1,r=n,ans=n;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(solve(a,mid,base)){
              ans = mid;
              r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};