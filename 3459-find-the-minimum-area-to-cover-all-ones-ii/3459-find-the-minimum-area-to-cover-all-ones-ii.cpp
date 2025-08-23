class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return calc(grid, n, m);
    }

private:
    int sum(vector<vector<int>>& grid, int l, int r, int u, int d) {
        if (l >= r || u >= d) return 0;
        int min_row = INT_MAX, max_row = INT_MIN, min_col = INT_MAX, max_col = INT_MIN;
        bool found = false;
        for (int i = l; i < r; i++) {
            for (int j = u; j < d; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    min_row = min(min_row, i);
                    max_row = max(max_row, i);
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }
        if (!found) return 0;
        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }

    int calc(vector<vector<int>>& grid, int n, int m) {
        int res = INT_MAX;

        for (int i = 1; i < n - 1; i++){
        int temp = sum(grid, 0, i, 0, m);
            for (int j = i + 1; j < n; j++)
                res = min(res, temp + sum(grid, i, j, 0, m) + sum(grid, j, n, 0, m));
        }

        for (int j = 1; j < m - 1; j++){
        int temp = sum(grid, 0, n, 0, j);
            for (int i = j + 1; i < m; i++)
                res = min(res, temp + sum(grid, 0, n, j, i) + sum(grid, 0, n, i, m));
        }

        for (int i = 1; i < n; i++){
        int temp = sum(grid, i, n, 0, m);
            for (int j = 1; j < m; j++)
                res = min(res, sum(grid, 0, i, 0, j) + sum(grid, 0, i, j, m) + temp);
        }

        for (int i = 1; i < n; i++){
            int temp = sum(grid, 0, i, 0, m);
            for (int j = 1; j < m; j++)
                res = min(res, sum(grid, i, n, 0, j) + sum(grid, i, n, j, m) + temp);
        }

        for (int j = 1; j < m; j++){
            int temp = sum(grid, 0, n, j, m);
            for (int i = 1; i < n; i++)
                res = min(res, sum(grid, 0, i, 0, j) + sum(grid, i, n, 0, j) + temp);
        }

        for (int j = 1; j < m; j++){
            int temp = sum(grid, 0, n, 0, j);
            for (int i = 1; i < n; i++)
                res = min(res, sum(grid, 0, i, j, m) + sum(grid, i, n, j, m) + temp);
        }

        return res == INT_MAX ? 0 : res;
    }
};
