class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    res += count(mat, i, j);
                }
            }
        }
        return res;
    }
    int count(vector<vector<int>>& matrix, int r, int c) {
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        int min_val = m;  

        for (int i = r; i < n && matrix[i][c] == 1; i++) {
            int len = 0;
            for (int j = c; j < m && matrix[i][j] == 1; j++) {
                len++;
            }
            min_val = min(min_val, len);
            res += min_val;
        }
        return res;
    }
};