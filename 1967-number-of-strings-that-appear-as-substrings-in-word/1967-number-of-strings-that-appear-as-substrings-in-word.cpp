class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<char,vector<int>> mp;
        int n = word.size();
        for(int i=0;i<n;i++)  
            mp[word[i]].push_back(i);
        int ans=0;
        for(auto &wo : patterns){
            bool ok = false; 
            if(mp.count(wo[0])){
                for(auto &idx : mp[wo[0]]){
                    bool match = true; 
                    for(int i=0;i<wo.size() && i+idx<n;i++)
                        if(wo[i]!=word[i+idx]){
                            match = false;
                            break;
                        }
                    if(match && idx + wo.size() <= n){ 
                        ok = true;
                        break;
                    }
                    }
            }
            if(ok) ans++;
        }

        return ans;
    }
};