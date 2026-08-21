class Solution {
public:

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long con(vector<int>& a, long long mid) {

        int n = a.size();
        long long res = 0;

        for(int ex = 1; ex < (1 << n); ex++) {

            int od = 0;
            long long lcm = 1;

            for(int i = 0; i < n; i++) {

                if(ex & (1 << i)) {

                    od++;

                    long long g = gcd(lcm, a[i]);

                    // overflow avoid
                    if(lcm > mid / (a[i] / g)) {
                        lcm = mid + 1;
                        break;
                    }

                    lcm = lcm / g * a[i];
                }
            }

            if(lcm > mid)
                continue;

            if(od % 2 == 0)
                res -= mid / lcm;
            else
                res += mid / lcm;
        }

        return res;
    }

    long long findKthSmallest(vector<int>& a, int k) {

        int n = a.size();

        // 1 present => every positive integer is possible
        for(int x : a) {
            if(x == 1)
                return k;
        }

        // Remove only truly redundant numbers
        set<int> st(a.begin(), a.end());

        vector<int> v(st.begin(), st.end());

        set<int> remove;

        for(int i = 0; i < v.size(); i++) {

            for(int j = 0; j < v.size(); j++) {

                if(i != j && v[j] % v[i] == 0) {
                    remove.insert(v[j]);
                }
            }
        }

        vector<int> b;

        for(int x : v) {
            if(!remove.count(x))
                b.push_back(x);
        }

        if(b.size() == 1)
            return 1LL * b[0] * k;

        long long l = 1;
        long long r = 1LL * b.back() * k;
        long long res = -1;

        while(l <= r) {

            long long mid = l + (r-l)/2;

            if(con(b, mid) >= k) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }
};