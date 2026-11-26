class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = n>=10;
        bool turn=true;
        for(int i=10;i>0;i--){
            if(turn){
                if(n-i>=0)
                n=n-i;
                else return false;
                turn =false;
            }
            else{
                if(n-i>=0)
                n=n-i;
                else return true;
                turn =true;
            }

        }
        return true;
    }
};