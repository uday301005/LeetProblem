class Solution {
public:
     vector<int> a = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sol(string s){
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3));
        return a[m-1]+d;
     }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        for(int i=1;i<a.size();i++)
            a[i] += a[i-1];
        return max(0,min(sol(leaveBob),sol(leaveAlice))-max(sol(arriveAlice),sol(arriveBob))+1);
    }
};