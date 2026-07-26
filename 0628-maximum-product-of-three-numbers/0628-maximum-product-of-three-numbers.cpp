class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=-1000,b=-1000,c=-1000,p=1000,q=1000;
        for(auto & x : nums){
            if(x>a){
                c=b;
                b=a;
                a=x;
            }
            else if(x>b){
                c=b;
                b=x;
            }
            else if(x>c)
             c=x;
            
            if(x<p){
                q=p;
                p=x;
            }
            else if(x<q)
              q=x;
            
        }
        return max(a*p*q, a*b*c);
    }
};