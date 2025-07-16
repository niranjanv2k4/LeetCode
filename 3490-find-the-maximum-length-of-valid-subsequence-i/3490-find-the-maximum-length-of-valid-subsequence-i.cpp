class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int dp[2][2] = {{0,0},{0,0}};
        int ans = 0;
        for (int x : nums) {
            int p = x % 2;
            for (int j = 0; j < 2; j++) {
                dp[p][j] = dp[j][p] + 1;
                ans = max(ans, dp[p][j]);
            }
        }
        return ans;
    }
};