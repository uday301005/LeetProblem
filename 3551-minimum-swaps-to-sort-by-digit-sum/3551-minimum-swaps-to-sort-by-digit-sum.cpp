class Solution {
public:
int sum(int num){
    int ans=0;
    while(num){
     ans += num%10;
     num /= 10;
    }
    return ans;
}
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        auto lambda = [this](int a ,int b){
           int x = sum(a) , y= sum(b);
           if(x!=y) return x<y;
           return a<b;
        };

       vector<int> temp = arr;
       sort(begin(temp),end(temp),lambda);
       for(int i=0;i<n;i++){
         mp[arr[i]] = i;
       }
       int c=0;
       for(int i=0;i<n;i++){
        int j = mp[temp[i]];
        if(i!=j){
            c++;
             mp[arr[i]] = j;
            mp[arr[j]] = i;
            swap(arr[i],arr[j]);
        }
       }
       return c;
    }
};