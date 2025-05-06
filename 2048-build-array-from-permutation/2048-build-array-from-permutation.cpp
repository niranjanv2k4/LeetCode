class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};