class Solution {
public:
    int smallestIndex(vector<int>& a) {
        int n= a.size();
        for(int i=0;i<n;i++){
            int num=a[i];
            int sum=0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            if(sum==i) return i;
        }

        return -1;
    }
};