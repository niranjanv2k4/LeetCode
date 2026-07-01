class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), high = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
        vector<int> dir = {-1, 0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    d[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc])
                    continue;

                d[nr][nc] = d[r][c] + 1;
                high = max(high, d[nr][nc]);
                q.push({nr, nc});
                vis[nr][nc] = true;
            }
        }

        auto recurse = [&](auto&& self, int r, int c, vector<vector<bool>>& vis,
                           int limit) -> bool {
            if (r < 0 || c < 0 || r >= n || c >= n || vis[r][c] ||
                d[r][c] < limit)
                return false;

            if (r == n - 1 && c == n - 1)
                return true;

            vis[r][c] = true;

            return self(self, r, c - 1, vis, limit) ||
                   self(self, r, c + 1, vis, limit) ||
                   self(self, r - 1, c, vis, limit) ||
                   self(self, r + 1, c, vis, limit);
        };

        int low = 0, res = 0;
        while (low <= high) {
            for (int i = 0; i < n; i++)
                fill(vis[i].begin(), vis[i].end(), false);

            int mid = (low + high) / 2;

            if (recurse(recurse, 0, 0, vis, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};