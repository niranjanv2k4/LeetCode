class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        vector<int> temp;
        int top = 0, left = 0;
        int bottom = grid.size() - 1, right = grid[0].size() - 1;

        while (top <= bottom && left <= right) {

            int prev_left = left, prev_right = right, prev_top = top,prev_bottom = bottom;
            vector<int> temp = get_array(grid, left, right, top, bottom, k);
            int idx = 0;

            for (int j = prev_left; j <= prev_right; j++)
                grid[prev_top][j] = temp[idx++];

            prev_top++;

            for (int j = prev_top; j <= prev_bottom; j++)
                grid[j][prev_right] = temp[idx++];

            prev_right--;

            for (int j = prev_right; j >= prev_left; j--)
                grid[prev_bottom][j] = temp[idx++];

            prev_bottom--;

            for (int j = prev_bottom; j >= prev_top; j--)
                grid[j][prev_left] = temp[idx++];

            prev_left++;
        }

        return grid;
    }

    vector<int> get_array(vector<vector<int>>& grid, int& left, int& right,
                          int& top, int& bottom, int k) {

        vector<int> temp;

        for (int j = left; j <= right; j++)
            temp.push_back(grid[top][j]);

        top++;

        for (int j = top; j <= bottom; j++)
            temp.push_back(grid[j][right]);

        right--;

        for (int j = right; j >= left; j--)
            temp.push_back(grid[bottom][j]);

        bottom--;

        for (int j = bottom; j >= top; j--)
            temp.push_back(grid[j][left]);

        left++;

        k %= temp.size();

        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());
        reverse(temp.begin(), temp.end());

        return temp;
    }
};