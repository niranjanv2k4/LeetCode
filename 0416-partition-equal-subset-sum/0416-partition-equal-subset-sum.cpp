class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int target = accumulate(nums.begin(), nums.end(), 0);

        if (target % 2 != 0)
            return false;

        int n = nums.size();
        vector<bool> dp(target + 1, false);
        
        dp[0] = true;
        target /= 2;

        for (int i = 1; i <= n; i++) {
            for (int j = target + 1; j >= 0; j--) {
                if (j >= nums[i - 1])
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }
};