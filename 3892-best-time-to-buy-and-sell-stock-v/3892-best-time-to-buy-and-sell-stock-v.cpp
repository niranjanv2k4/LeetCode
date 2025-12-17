class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        return recurse(prices, n - 1, k, 0, dp);
    }

    long long recurse(vector<int>& prices, int i, int j, int state,
                      vector<vector<vector<long long>>>& dp) {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            if (state == 0)
                return 0;
            return state == 1 ? -prices[0] : prices[0];
        }

        if (dp[i][j][state] != -1) {
            return dp[i][j][state];
        }

        long long res = INT_MIN;

        if (state == 0) {
            res = max(recurse(prices, i - 1, j, 0, dp),
                      max(recurse(prices, i - 1, j, 1, dp) + prices[i],
                          recurse(prices, i - 1, j, 2, dp) - prices[i]));
        } else if (state == 1) {
            res = max(recurse(prices, i - 1, j, 1, dp),
                      recurse(prices, i - 1, j - 1, 0, dp) - prices[i]);
        } else {
            res = max(recurse(prices, i - 1, j, 2, dp),
                      recurse(prices, i - 1, j - 1, 0, dp) + prices[i]);
        }

        return dp[i][j][state] = res;
    }
};
