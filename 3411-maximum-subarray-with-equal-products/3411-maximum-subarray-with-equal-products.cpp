class Solution {
public:
  
    int maxLength(vector<int>& a) {
       int n=a.size(),ans=0;
       vector<int> freq(10,false);  
       int st=0,end=0;
        for(int i=0;i<n-1;i++){
            int g=a[i],p=a[i],l=a[i];
            for(int j=i+1;j<n;j++){
                g = gcd(g,a[j]);
                p *= a[j];
                l=lcm(l,a[j]);
                if(p>g*l) break;
                if(p==g*l)
                ans = max(ans,j-i+1);
            }
        }  
        return ans;
    }
};