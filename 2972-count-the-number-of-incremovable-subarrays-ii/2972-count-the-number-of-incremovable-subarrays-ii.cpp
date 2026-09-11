class Solution {
public:
int n;
bool check(vector<int> & a , int st, int end){
    if(st==0){
        if(end>=n-2) return true;
        for(int i=end+1;i<n-1;i++)
         if(a[i] >= a[i+1]) return false;
    }
    else if(end==n-1){
        if(st<=1) return true;
        for(int i=0;i<st-1;i++)
         if(a[i] >= a[i+1]) return false;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(i+1==st){
              if(a[i] >= a[end+1]) return false;
              i=end;
            }
            else{
                if(a[i]>=a[i+1]) return false;
            }
        }
    }
    return true;
}




    long long incremovableSubarrayCount(vector<int>& a) {
    n = a.size();
    long long ans =0; 
        // for(int i=0;i<n;i++)
        //     for(int j=i;j<n;j++)
        //         if(check(a,i,j)){  ans += n-j;  break;}
    int x=0,y=n-1;
    for(int i=1;i<n;i++)
       if(a[i-1]<a[i])
         x=i;
        else break;
    for(int i=n-2;i>=0;i--)
       if(a[i]<a[i+1])
         y=i;
         else
         break;
     if(x == n-1)
            return 1LL * n * (n+1) / 2;
        ans += n - y + 1;
        ans += x + 1;

    for(int i=0;i<=x;i++){
    int j = lower_bound(a.begin() + y, a.end(), a[i] + 1) - a.begin();
    if(j != -1)
        ans += n-j;
} 
return ans;
    }
};