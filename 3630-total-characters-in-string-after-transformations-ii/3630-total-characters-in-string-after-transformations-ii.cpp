class Solution {
public:
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {

        auto matrix = create(nums);
        auto result = identityMatrix();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        while (t > 0) {
            if (t & 1)
                result = matrixMultiply(matrix, result);
            matrix = matrixMultiply(matrix, matrix);
            t >>= 1;
        }

        int val = 0;
        vector<int> final(26, 0);
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                final[i] = (final[i] + (1LL*result[i][j] * freq[j]) % MOD) % MOD;

        for (int count : final) {
            val = (val + count) % MOD;
        }
        return val;
    }
    vector<vector<int>> create(const vector<int>& nums) {
        vector<vector<int>> matrix(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                matrix[(i + j) % 26][i] = 1;
            }
        }
        return matrix;
    }

    vector<vector<int>> identityMatrix() {
        vector<vector<int>> matrix(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            matrix[i][i] = 1;
        }
        return matrix;
    }
    vector<vector<int>> matrixMultiply(const vector<vector<int>>& A,
                                       const vector<vector<int>>& B) {
        vector<vector<int>> res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    res[i][j] =
                        (res[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }
};