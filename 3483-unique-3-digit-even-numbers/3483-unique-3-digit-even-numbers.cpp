class Solution {
public:
    int totalNumbers(vector<int>& a) {
        bool vis[1000]{};
        int ans=0,n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==0) continue;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==i ||k==j || a[k]%2==1) continue;
                    int x = a[i]*100+a[j]*10+a[k];
                    if(!vis[x]){
                        vis[x]= true;
                        ans++;
                    } 
                }
            }
        }
        return ans;
    }
};