class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int s=10;
        while(n>=s){
            n -= s--;
            alice = !alice;
        }
        return !alice;
    }
};