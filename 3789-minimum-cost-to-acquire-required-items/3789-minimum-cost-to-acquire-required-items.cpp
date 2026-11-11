class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2<=costBoth)
            ans += 1LL*min(need1,need2)*(cost1+cost2);
        else 
        ans += 1LL*min(need1,need2)*(costBoth);
    
       if(need1>need2){
        int diff=need1-need2;
       ans += min(costBoth,cost1)*1LL*diff;
       }
       else if(need2>need1){
        int diff = need2-need1;
       ans += min(costBoth,cost2)*1LL*diff;
       }
return ans;
    }
};