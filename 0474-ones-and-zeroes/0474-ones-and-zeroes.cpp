class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(
            strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return recurse(strs, 0, m, n, 0, 0, dp);
    }
    int recurse(vector<string>& strs, int idx, int m, int n, int cm, int cn,
                vector<vector<vector<int>>>& dp) {
        if (idx == strs.size()) {
            return 0;
        }

        if (dp[idx][cm][cn] != -1)
            return dp[idx][cm][cn];

        int non_take = recurse(strs, idx + 1, m, n, cm, cn, dp);
        int take = INT_MIN;
        int one = cn + count(strs[idx].begin(), strs[idx].end(), '1');
        int zero = cm + count(strs[idx].begin(), strs[idx].end(), '0');

        if (one <= n && zero <= m) {
            take = recurse(strs, idx + 1, m, n, zero, one, dp) + 1;
        }

        return dp[idx][cm][cn] = max(take, non_take);
    }
};