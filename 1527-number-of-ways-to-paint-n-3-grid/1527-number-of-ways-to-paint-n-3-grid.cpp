class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(
            n + 1, vector<vector<vector<int>>>(
                       4, vector<vector<int>>(4, vector<int>(4, -1))));
        return recurse(dp, n, 0, 0, 0);
    }
    int recurse(vector<vector<vector<vector<int>>>>& dp, int row, int c1,
                int c2, int c3) {
        if (row == 0)
            return 1;

        if (dp[row][c1][c2][c3] != -1)
            return dp[row][c1][c2][c3];

        int res = 0;

        for (int i = 1; i < 4; i++) {
            if (i == c1)
                continue;
            for (int j = 1; j < 4; j++) {
                if (j == i || j == c2)
                    continue;
                for (int k = 1; k < 4; k++) {
                    if (k == j || k == c3)
                        continue;
                    res = (res + recurse(dp, row - 1, i, j, k)) % MOD;
                }
            }
        }

        return dp[row][c1][c2][c3] = res;
    }
};