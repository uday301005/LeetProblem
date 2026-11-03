class Solution {
public:
    int minMoves(vector<int>& a) {
        return a.size()*(*max_element(begin(a),end(a))) - accumulate(begin(a),end(a),0);
    }
};