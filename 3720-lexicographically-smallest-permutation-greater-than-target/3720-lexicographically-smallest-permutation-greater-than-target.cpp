class Solution {
public:
int n;
string res="";

// void per(string s,int i){
//    if(i==n) {
//     cout<<s<<endl;
//      res = s;
//      return;
//    }
//    for(int j=i;j<n;j++){
//     swap(s[i],s[j]);
//     per(s,i+1);
//     swap(s[i],s[j]);
//    }
// }
bool solve(vector<int> & freq, string & curr,string & t, int idx, bool great ){
    if(idx==t.size()){
        if(great){
            res = curr;
            return true;
        }
        return false;
    }

    for(char ch='a'; ch<='z';ch++){
        if(freq[ch-'a'] == 0) continue;
        if(!great && ch < t[idx]) continue;

        curr.push_back(ch);
        freq[ch-'a']--;
        bool isgreat = great || ch > t[idx];
        if(solve(freq,curr,t,idx+1,isgreat)) return true;
        curr.pop_back();
        freq[ch-'a']++;
    }
     return false;
}
    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        vector<int> freq(26,0);
        for(char c : s)     freq[c-'a']++;
        string curr;
        solve(freq,curr,target,0,false);
        return res;
    }
};