class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int k = 1; k < n; ++k) {
            for (int j = 0; j < n; ++j) { 
                for (int i = 0; i + 1 < n && k + i + 1 < n; ++i) {
                    if (grid[i][k + i] > grid[i + 1][k + i + 1]) {
                        swap(grid[i][k + i], grid[i + 1][k + i + 1]);
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) { 
                for (int i = k; i + 1 < n; ++i) {
                    int col = i - k;               
                    if (col + 1 >= n) break;       
                    if (grid[i][col] < grid[i + 1][col + 1]) {
                        swap(grid[i][col], grid[i + 1][col + 1]);
                    }
                }
            }
        }

        return grid;
    }
};
