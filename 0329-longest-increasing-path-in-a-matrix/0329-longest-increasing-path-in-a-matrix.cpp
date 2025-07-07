class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        const int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, recurse(matrix, i, j, INT_MIN, dp));
            }
        }

        return res;
    }
    int recurse(vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<int>>& dp) {

        if (r >= matrix.size() || r < 0 || matrix[0].size() <= c || c < 0 ||prev >= matrix[r][c]) {
            return 0;
        }

        if (dp[r][c] != -1)
            return dp[r][c];

        int left = recurse(matrix, r, c - 1, matrix[r][c], dp);
        int right = recurse(matrix, r, c + 1, matrix[r][c], dp);
        int up = recurse(matrix, r - 1, c, matrix[r][c], dp);
        int down = recurse(matrix, r + 1, c, matrix[r][c], dp);

        return dp[r][c] = 1 + max({left, right, up, down});
    }
};