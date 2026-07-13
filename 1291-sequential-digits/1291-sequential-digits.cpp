class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        vector<int> res;
        for(int i=1;i<10;i++) que.push(i);

        while(!que.empty()){
            int digit = que.front();
            if(digit > high) break;
            que.pop();
            if(low <= digit && digit <= high)
             res.push_back(digit);
            int c = digit%10;
            if(c!=9){
                digit = digit*10 + c+1;
                que.push(digit);
            }
        }
  return res;
    }
};