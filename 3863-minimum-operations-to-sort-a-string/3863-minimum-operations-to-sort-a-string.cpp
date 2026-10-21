class Solution {
public:
    int minOperations(string s) {
        int n= s.size();
        bool is=true;
        for(int i=0;i<n-1;i++)
        if(s[i]>s[i+1]){
            is=false;
            break;
        }
        if(is) return 0;
        int mn=n-1,mx=0;
        for(int i=0;i<n;i++)
            if(s[i]>=s[mx])
            mx=i;
        for(int i=n-1;i>=0;i--)
            if(s[i]<=s[mn])
            mn=i;
        if(mn==0||mx==n-1) return 1;
        if(mn!=0 && mx!= n-1){
            if(n==2) return -1;
           if(mn==n-1 && mx==0) return 3;
        }
return 2;
    }
};