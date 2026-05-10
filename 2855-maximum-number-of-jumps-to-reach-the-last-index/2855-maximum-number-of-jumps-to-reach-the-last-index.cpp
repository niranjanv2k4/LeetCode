class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), 0);
        int n = nums.size();

        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (-target <= nums[j] - nums[i] &&
                    nums[j] - nums[i] <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] == 1)
                    dp[i] = 0;
            }
        }

        return dp[0] == 1 ? -1 : dp[0] - 1;
    }
};