class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> mark = matrix;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mark[i][j] == 0) {
                    int u = i - 1, d = i + 1, l = j - 1, r = j + 1;
                    while (u >= 0 || l >= 0 || d < n || r < m) {
                        if (u >= 0) 
                            matrix[u--][j] = 0;
                        if (l >= 0) 
                            matrix[i][l--] = 0;
                        if (d < n) 
                            matrix[d++][j] = 0;
                        if (r < m) 
                            matrix[i][r++] = 0;
                    }
                }
            }
        }
    }
};