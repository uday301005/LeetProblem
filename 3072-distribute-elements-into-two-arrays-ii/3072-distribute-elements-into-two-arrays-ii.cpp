class segTree {
public:
    static constexpr int MAX = 1e7;
    int m;
    vector<int> seg;
    segTree(int size) {
        m =size;
        seg.resize(4 * m, 0);
    }
    void update(int i, int l, int r, int idx) {
        if (l == r) {
            seg[i] ++;        
            return;
        }
        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * i + 1, l, mid, idx);
        else
            update(2 * i + 2, mid + 1, r, idx);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int query(int i, int l, int r, int st, int en) {
        if (l > en || r < st)
            return 0;

        if (st <= l && r <= en)
            return seg[i];

        int mid = l + (r - l) / 2;

        return query(2 * i + 1, l, mid, st, en) +
               query(2 * i + 2, mid + 1, r, st, en);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        int n = a.size();
        if (n <= 2)   return a;
       vector<int> sortedNums(begin(a), end(a));
        sort(begin(sortedNums), end(sortedNums));
        unordered_map<int, int> mp; 
        int com = 0;
        for(int &num : sortedNums) if(!mp.count(num))   mp[num] = com++;
        int m = mp.size();
        vector<int> a1, a2, res;
        segTree seg1(m), seg2(m);
        a1.push_back(a[0]);
        a2.push_back(a[1]);
        seg1.update(0, 0, m - 1, mp[a[0]]);
        seg2.update(0, 0, m - 1, mp[a[1]]);

        for (int i = 2; i < n; i++) {
             int cv = mp[a[i]];
            int x = seg1.query(0, 0, m - 1,  cv+1, m-1);
            int y = seg2.query(0, 0, m- 1,cv+1, m - 1);
            bool add1 = false;
            if (x > y) 
                 add1 = true;
            else if (x < y) 
                 add1 = false;
            else 
                 add1 = a1.size() <= a2.size();
            if(add1) {
                 a1.push_back(a[i]);
                seg1.update(0, 0, m - 1, cv);
            }
            else{
                 a2.push_back(a[i]);
                seg2.update(0, 0, m - 1, cv);
            }
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};