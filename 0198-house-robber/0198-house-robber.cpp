class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return maxMoney(nums, dp, 0);
    }
    int maxMoney(const vector<int>& nums, vector<int>& dp, int idx) {
        if (idx >= nums.size()) 
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];
        int two = nums[idx] + maxMoney(nums, dp, idx + 2);
        int one = maxMoney(nums, dp, idx + 1);
        return dp[idx] = max(two, one);
    }
};