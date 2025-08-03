class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = grid[0].size(), n = grid.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        grid[i][j] = 0;
                    }
                }
                if (grid[i][j] == 1)
                    res++;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (!(nr == n || nc == m || nr < 0 || nc < 0) && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    res--;
                    q.push({nr, nc});
                }
            }
        }

        return res;
    }
};