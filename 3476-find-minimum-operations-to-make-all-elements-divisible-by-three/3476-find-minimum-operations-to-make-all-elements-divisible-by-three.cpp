class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int el : nums) {
            el = el % 3;
            res += min(3 - el, el);
        }
        return res;
    }
};