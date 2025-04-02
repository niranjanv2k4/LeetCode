class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        vector<int> dp(n);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                dp[i] = INT_MAX;
                continue;
            }
            if (nums[i] + i >= n - 1) {
                dp[i] = 1;
            } else {
                int j = 0;
                int min = INT_MAX;
                while (i + j + 1 < n && j < nums[i]) {
                    min = min < dp[i + j + 1] ? min : dp[i + j + 1];
                    j++;
                }
                dp[i] = min == INT_MAX ? min : min + 1;
            }
        }
        return dp[0];
    }
};