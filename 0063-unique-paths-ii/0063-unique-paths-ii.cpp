class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int m = grid[0].size(), n = grid.size();
        vector<int> dp(m);
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && flag)
                flag = false;
            dp[i] = flag ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 1)
                dp[0] = 0;
            for (int j = 1; j < m; j++) 
                dp[j] = grid[i][j] ? 0 : dp[j] + dp[j - 1];
        }
        return dp[m - 1];
    }
};