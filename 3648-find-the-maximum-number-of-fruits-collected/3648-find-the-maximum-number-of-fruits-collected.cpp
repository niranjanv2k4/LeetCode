class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0;
        int n = fruits.size();
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        int one = recursedown(fruits, 0, n - 1, dp1);
        int two = recurseleft(fruits, n - 1, 0, dp2);

        return res + one + two;
    }

    int recursedown(vector<vector<int>>& grid, int r, int c,
                    vector<vector<int>>& dp) {

        if (r == grid.size() - 2 && c == grid.size() - 1)
            return grid[r][c];

        if (c <= r || c == grid.size() || r == grid.size())
            return 0;

        if (dp[r][c] != -1)
            return dp[r][c];
        int res = grid[r][c];

        int one = recursedown(grid, r + 1, c - 1, dp);
        int two = recursedown(grid, r + 1, c, dp);
        int three = recursedown(grid, r + 1, c + 1, dp);

        return dp[r][c] = res + max({one, two, three});
    }
    int recurseleft(vector<vector<int>>& grid, int r, int c,
                    vector<vector<int>>& dp) {

        if (c == grid.size() - 2 && r == grid.size() - 1)
            return grid[r][c];

        if (r <= c || c == grid.size() || r == grid.size())
            return 0;

        if (dp[r][c] != -1)
            return dp[r][c];
        int res = grid[r][c];

        int one = recurseleft(grid, r - 1, c + 1, dp);
        int two = recurseleft(grid, r, c + 1, dp);
        int three = recurseleft(grid, r + 1, c + 1, dp);

        return dp[r][c] = res + max({one, two, three});
    }
};