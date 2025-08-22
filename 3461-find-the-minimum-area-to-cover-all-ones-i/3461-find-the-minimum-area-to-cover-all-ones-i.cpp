class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int r = 0, d = 0, l = INT_MAX, u = INT_MAX;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    u = min(u, i);
                    d = max(d, i);

                    l = min(l, j);
                    r = max(r, j);
                }
            }
        }


        return (r - l + 1) * (d - u + 1);
    }
};