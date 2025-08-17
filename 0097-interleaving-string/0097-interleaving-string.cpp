class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(s3.size()+1, vector<int>(s3.size()+1, -1));
        return recurse(0, 0, s1, s2, s3, '\0', dp);
    }

    bool recurse(int i1, int i2, string& s1, string& s2, string& s3, char curr,
                 vector<vector<int>>& dp) {
        if (i1 + i2 - 1 >= 0 && curr != s3[i1 + i2 - 1])
            return false;

        if (dp[i1][i2] != -1)
            return dp[i1][i2];

        if (i1 + i2 == s3.size()) {
            return true;
        }

        for (int i = i1; i < s1.size(); i++) {
            if (recurse(i1 + 1, i2, s1, s2, s3, s1[i1], dp)) {
                return dp[i1][i2] = true;
            }
        }
        for (int i = i2; i < s2.size(); i++) {
            if (recurse(i1, i2 + 1, s1, s2, s3, s2[i2], dp)) {
                return dp[i1][i2] = true;
            }
        }

        return dp[i1][i2] = false;
    }
};