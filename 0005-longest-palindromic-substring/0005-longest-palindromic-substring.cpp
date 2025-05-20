class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string maxStr = s.substr(0, 1);
        int maxLen = 1;
        s = "#" + regex_replace(s, regex(""), "#") + "#";
        const int n = s.size();

        vector<int> dp(s.size(), 0);
        int center = 0, right = 0;

        for (int i = 0; i < n; i++) {
            if (i < right)
                dp[i] = min(right - i, dp[2 * center - i]);
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n &&
                   s[i - dp[i] - 1] == s[i + dp[i] + 1])
                dp[i]++;

            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(remove(maxStr.begin(), maxStr.end(), '#'),
                             maxStr.end());
            }
        }
        return maxStr;
    }
};