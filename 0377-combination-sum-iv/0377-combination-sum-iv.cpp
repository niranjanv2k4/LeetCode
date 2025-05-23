class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 1);
        for (int i = 1; i <= target; i++) {
            long long res = 0;
            for (int num : nums)
                res += i < num ? 0 : dp[i - num];

            dp[i] = res;
        }
        return dp[target];
    }
};