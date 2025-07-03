class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];

        vector<int> dp(n, 0);
        int res = dp[0] = triangle[0][0];

        for (int r = 1; r < n; r++) {
            dp[r] = dp[r - 1] + triangle[r][r];
            for (int c = r - 1; c > 0; c--) {
                dp[c] = triangle[r][c] + min(dp[c], dp[c - 1]);
            }
            dp[0] += triangle[r][0];
        }

        return *min_element(dp.begin(), dp.end());
    }
};