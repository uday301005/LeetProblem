class Solution {
public:


bool check(string & res , string & temp ){
    if (res == "") return true;
    if (temp.size() < res.size()) return true;
    if (temp.size() > res.size()) return false;
        return temp < res;
    }
string solve(string s,int k){
    int n=s.size();
    string res="";
    for(int i=0;i<n;i++){
        int ones=0;
      for(int j=i;j<n;j++){
         if(s[j] == '1') ones++;
         if(ones == k){
            string temp = s.substr(i,j-i+1);
            if(check(res,temp))
            res=temp;
            break;
         }
       }
      }
      return res;
}

    string shortestBeautifulSubstring(string s, int k) {
        return solve(s,k);
        int n = s.size(),st=0,end=0;
        string res = "",temp="";
        while(true){
          if(__builtin_popcount(stoi(temp)) <= k){
             if(end<n){
                temp.push_back(s[end]);
                 end++;
             }
             else break;
          }
          else {
            if(st<n){
            temp.erase(temp.begin());
              st++;
            }
            else break;
          }
          if(__builtin_popcount(stoi(temp)) == k)
             if(check(res,temp) )
                res = temp;
        }
return res;
    }
};