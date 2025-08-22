class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int r = 0, d = 0, l = INT_MAX, u = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (col[i] != 0) {
                r = i;
                l = min(i, l);
            }
        }
        for (int i = 0; i < n; i++) {
            if (row[i] != 0) {
                d = i;
                u = min(i, u);
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
};