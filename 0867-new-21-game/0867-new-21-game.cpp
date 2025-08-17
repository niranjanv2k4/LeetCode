class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        if (k == 0)
            return 1;
            
        vector<double> dp(n + maxPts + 1, 0);
        for (int i = k; i <= n; i++) {
            dp[i] = 1;
        }

        double curr = 0;
        for (int j = k; j <= k - 1 + maxPts; j++) {
            curr += dp[j];
        }

        dp[k - 1] = curr / maxPts;
        for (int i = k - 2; i >= 0; i--) {
            curr = curr + dp[i + 1] - dp[i + maxPts + 1];
            dp[i] = curr / maxPts;
        }
        return dp[0];
    }
};