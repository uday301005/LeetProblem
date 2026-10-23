class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int k = pow(2,31)-1,n=a.size();
        for(int i=0;i<n;i++)
         if(a[i]!=i)
         k = k&a[i];

         return k==pow(2,31)-1 ? 0 : k;
    }
};