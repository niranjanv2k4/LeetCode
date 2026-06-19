class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, curr = 0;
        for(int el : gain){
            curr += el;
            res = max(res, curr);
        }
        return res;
    }
};