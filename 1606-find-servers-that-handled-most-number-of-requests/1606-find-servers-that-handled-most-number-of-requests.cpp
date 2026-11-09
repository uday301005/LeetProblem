class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        int n = a.size(),m=0;
        set<int> avil;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > busy;
        vector<int> count(k,0);
        for(int i=0;i<k;i++)
        avil.insert(i);
        for(int i=0;i<n;i++){
            while(!busy.empty() && busy.top().first<=a[i]){
                int s = busy.top().second;
                busy.pop();
                avil.insert(s);
            }

            int s=i%k;
            auto it = avil.lower_bound(s);
            if(it==avil.end()) {
                it = avil.begin();
            }
            if(avil.empty()) continue;
            s = *it;
            avil.erase(it);
           busy.push({a[i]+l[i],s});
           count[s]++;
           m=max(m,count[s]);
        }
        vector<int> res;
        for(int i=0;i<k;i++)
         if(count[i]==m && count[i] !=0)
          res.push_back(i);
    return res;
    }
};