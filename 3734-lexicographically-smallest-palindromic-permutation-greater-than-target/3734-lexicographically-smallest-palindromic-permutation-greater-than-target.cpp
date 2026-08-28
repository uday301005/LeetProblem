class Solution {
public:
char mid = '#';
string res="";
bool solve(vector<int> & freq, string & curr , string & t , int i ,bool great){
    if(i == t.size()/2){
          string c2 = curr,c1=curr;
          reverse(begin(c2),end(c2));
          if(mid!='#')  c1 += mid;
           c1 += c2;
           if(c1>t) {
            res = c1;
            return true;
           }

        return false;
    }
    for(char ch = 'a' ; ch<='z' ; ch++){
        if(freq[ch-'a']==0)continue;
        if(!great && ch<t[i]) continue;

        curr.push_back(ch);
        freq[ch-'a']--;
        bool isGreat = great || ch>t[i];

        if(solve(freq,curr,t,i+1,isGreat))
         return true;

       curr.pop_back();
       freq[ch-'a']++; 
    }
    return false;
}
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26,0);
        for(char x : s)
         freq[x-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                if(mid != '#') return "";
                mid = i+'a'; 
            }
            freq[i] /= 2;
        }
      string curr="";
      solve(freq,curr,target,0,false);
    return res;
    }
};