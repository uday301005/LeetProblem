class Solution {
public:
    string smallestPalindrome(string s) {
        int n  = s.size();
        char l='0';
        if(n%2==1) l = s[n/2];
        vector<int> a(26,0);
        for(int i=0;i<n;i++){
            if(n%2==1 && i==n/2) continue;
             a[s[i]-'a']++;
        }
        string s1;
        for(int i=0;i<26;i++){
            int c = a[i]/2;
            while(c--){
          s1.push_back(i+'a');
            }
        }
       string  s2 = s1;
        reverse(begin(s2),end(s2));
        if(l!='0') s1.push_back(l);

        return s1+s2;
    }
    
};