class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, temp = 0;
        for (int num : nums) {
            temp += num;
            res = max(temp, res);
            if (temp < 0)
                temp = 0;
        }
        return res;
    }
};