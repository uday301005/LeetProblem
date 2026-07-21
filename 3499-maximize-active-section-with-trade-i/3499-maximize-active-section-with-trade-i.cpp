class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int active = 0,c=0;
        vector<int> pic;
         int i = 0;
        while(i < s.size()) {
            if(s[i] == '0') {
                int start = i;
                while(i < s.size() && s[i] == '0') i++;
               pic.push_back(i-start);
            } else {
                active++;
                i++;
            }
        }
        int mx = 0,n=pic.size();
        if(n<2) return active;
        for(int i=1;i<n;i++)
         mx = max(mx,pic[i]+pic[i-1]);
        
        return mx+active;
    }
};