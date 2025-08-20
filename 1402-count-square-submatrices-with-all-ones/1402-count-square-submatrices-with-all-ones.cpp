class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    res += count(matrix, i, j);
                }
            }
        }
        return res;
    }

    int count(vector<vector<int>>& matrix, int r, int c) {
        int m = matrix[0].size(), n = matrix.size();

        int res = 0;
        int size = min(n - r, m - c);
        for (int k = 1; k <= size; k++) {
            bool flag = true;
            for (int i = r; i < r + k; i++) {
                for (int j = c; j < c + k; j++) {
                    if (matrix[i][j] == 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag)break;
            res++;
        }

        return res;
    }
};