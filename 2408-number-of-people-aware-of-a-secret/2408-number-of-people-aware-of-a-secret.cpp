class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1), diff(n + 1);

        dp[1] = 1;
        diff[1 + delay] = (diff[1 + delay] + 1) % MOD;
        if (1 + forget <= n) {
            diff[1 + forget] = (diff[1 + forget] - 1 + MOD) % MOD;
        }

        long long temp = 0;

        for (int i = 2; i <= n; i++) {
            temp = (temp + diff[i]) % MOD;
            dp[i] = temp;

            if (dp[i] > 0) {
                if (i + delay <= n) {
                    diff[i + delay] = (diff[i + delay] + dp[i]) % MOD;
                }
                if (i + forget <= n) {
                    diff[i + forget] = (diff[i + forget] - dp[i] + MOD) % MOD;
                }
            }
        }

        long long res = 0;
        for(int i = n - forget + 1; i<=n; i++){
            if(i>0)res = (res + dp[i])%MOD;
        }
        return res;
    }
};