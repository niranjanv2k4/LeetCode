class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        vector<int> dir = {1, 1, -1, -1, 1};
        int n = grid.size(), m = grid[0].size();
        int res = 1;
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, -1));

        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(m,
                vector<vector<int>>(4, vector<int>(2, -1))));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    count++;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dir[k];
                        int nc = j + dir[k + 1];
                        if (nr < 0 || nc < 0 || nr == n || nc == m) {
                            continue;
                        }
                        if (grid[nr][nc] == 2) {
                            vis[i][j] = 1;
                            recurse(grid, dir, nr, nc, -1, 2, res, vis, k,
                                    false, dp);
                            vis[i][j] = -1;
                        }
                    }
                }
            }
        }
        if (!count)
            return 0;
        return res;
    }

    int recurse(vector<vector<int>>& grid, vector<int>& dir, int r, int c,
                int prev, int curr, int& max_len, vector<vector<int>>& vis,
                int d, bool flag,
                vector<vector<vector<vector<int>>>>& dp) {

        if (grid[r][c] == prev || vis[r][c] == 1) {
            return 0;
        }

        if (dp[r][c][d][flag] != -1) {
            max_len = max(max_len, curr + dp[r][c][d][flag] - 1);
            return dp[r][c][d][flag];
        }

        vis[r][c] = 1;
        max_len = max(curr, max_len);

        int max_path = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            if (nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size() ||
                grid[nr][nc] == 1) {
                continue;
            }

            if (i == d) {
                int path_len = recurse(grid, dir, nr, nc, grid[r][c], curr + 1,
                                       max_len, vis, i, flag, dp);
                max_path = max(max_path, 1 + path_len);
            } else if (!flag) {
                for (int k = 0; k < 4; k++) {
                    if (k == d) {
                        int nxt = (k + 1) % 4;
                        if (i == nxt) {
                            int path_len =
                                recurse(grid, dir, nr, nc, grid[r][c], curr + 1,
                                        max_len, vis, i, true, dp);
                            max_path = max(max_path, 1 + path_len);
                        }
                    }
                }
            }
        }

        dp[r][c][d][flag] = max_path;

        vis[r][c] = -1;
        return max_path;
    }
};
