class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        const int n = matrix.size();
        vector<int> dp = matrix[0], temp(n);

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int up = dp[c];
                int left = c - 1 < 0 ? INT_MAX : dp[c - 1];
                int right = c + 1 < n ? dp[c + 1] : INT_MAX;
                temp[c] = matrix[r][c] + min({up, left, right});
            }
            dp = temp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};