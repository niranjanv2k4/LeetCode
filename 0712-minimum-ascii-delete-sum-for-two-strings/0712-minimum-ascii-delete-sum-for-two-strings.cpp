class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));

        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);

        int max_val = recurse(s1, s2, 0, 0, dp);

        return sum1 + sum2 - 2 * max_val;
    }

    int recurse(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int res;
        if (s1[i] == s2[j]) {
            res = (int)s1[i] + recurse(s1, s2, i + 1, j + 1, dp);
        } else {
            res = max(recurse(s1, s2, i + 1, j, dp), recurse(s1, s2, i, j + 1, dp
            ));
        }
        return dp[i][j] = res;
    }
};