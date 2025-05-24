class Solution {
public:
    vector<vector<int>> pre;
    vector<int> dp;
    int m, n;
    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();
        int mask = 0;
        pre = vector<vector<int>>(n, vector<int>(n));
        dp = vector<int>(1 << n, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (students[i][k] == mentors[j][k])
                        pre[i][j]++;

        return recurse(0, mask);
    }

    int recurse(int idx, int mask) {
        if (idx == n)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        int maxVal = 0;
        int student = __builtin_popcount(mask);

        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j)))
                maxVal = max(maxVal, recurse(idx + 1, mask | (1 << j)) +
                                         pre[student][j]);
        }

        return dp[mask] = maxVal;
    }
};