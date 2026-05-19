class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = recurse(coins, amount, 0, dp);

        if(res == 1e9)
            return -1;

        return res;
    }

    int recurse(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0 || idx == coins.size())
            return 1e9;
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 1 + recurse(coins, amount - coins[idx], idx, dp);
        int not_take = recurse(coins, amount, idx + 1, dp);
        
        return  dp[idx][amount] = min(take, not_take);
    }
};