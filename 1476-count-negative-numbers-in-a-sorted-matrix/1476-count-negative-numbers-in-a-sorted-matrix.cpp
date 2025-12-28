class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() - 1;
        int i = 0, j = m;
        int res = 0;
        while(i<n){
            while(j >= 0 && grid[i][j] < 0){
                j--;
            }
            res += (m - j);
            i++;
        }
        return res;
    }
};