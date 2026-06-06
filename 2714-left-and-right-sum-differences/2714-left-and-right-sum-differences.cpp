class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left_sum = 0, right_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            left_sum += nums[i];
            res[i] = abs(left_sum - right_sum);
            right_sum -= nums[i];
        }

        return res;
    }
};