class Solution {
public:
 bool check(const vector<int>& src, const vector<int>& dis) {
        return search(
            src.begin(), src.end(),
            dis.begin(), dis.end()
        ) != src.end();
    }

    int sortableIntegers(vector<int>& a) {
        int n=a.size();
        vector<int> div;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                if(i != n/i) div.push_back(n/i);
            }
        }
        vector<int> temp= a;
        sort(begin(temp),end(temp));
     int c=0;
       for(int k : div){
        bool is=true;
          for(int i=0;i+k<=n;i+=k){
          vector<int> dis(a.begin()+i, a.begin()+i+k);
          vector<int> src(temp.begin()+i, temp.begin()+i+k);
            vector<int> doubled = src;
                doubled.insert(
                    doubled.end(),
                    src.begin(), src.end()
                );
             if(!check(doubled,dis)){
                is=false;
                break;
             }
          }
          if(is) c+=k;
       }
        return c;
    }
};