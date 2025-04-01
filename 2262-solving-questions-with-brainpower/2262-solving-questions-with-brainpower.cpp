class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        if (n == 1)
            return questions[0][0];

        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        long long result = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (questions[i][1] + i + 1 > n - 1)
                dp[i] =
                    dp[i + 1] > questions[i][0] ? dp[i + 1] : questions[i][0];

            else {
                long long val = dp[questions[i][1] + i + 1] + questions[i][0];
                dp[i] = dp[i + 1] > val ? dp[i + 1] : val;
            }

            result = max(result, dp[i]);
        }

        return result;
    }
};