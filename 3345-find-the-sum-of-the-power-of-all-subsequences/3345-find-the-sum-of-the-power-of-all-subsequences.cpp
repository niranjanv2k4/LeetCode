class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> pow_2 = vector<int>(101, 1);
    int dp[101][101][101];

    int sumOfPower(vector<int>& nums, int k) {
        int res = 0;
        init(nums.size());
        return generateSub(nums, k, 0, 0, 0)%MOD;
    }

    void init(int n) {
        for (int i = 1; i <= n; i++)
            pow_2[i] = pow_2[i - 1] * 2 % MOD;
        memset(dp, -1, sizeof(dp));
    }

    int generateSub(vector<int>& nums, int k, int idx, int size, int curr) {
        if (idx == nums.size() || curr > k) {
            return 0;
        }

        if (dp[curr][idx][size] != -1)
            return dp[curr][idx][size];

        int res = 0;

        if (curr + nums[idx] == k) {
            res = pow_2[nums.size() - size - 1] % MOD;
        }

        res = res +
              generateSub(nums, k, idx + 1, size + 1, curr + nums[idx]) % MOD;
        res = res + generateSub(nums, k, idx + 1, size, curr) % MOD;
        return dp[curr][idx][size] = res;
    }
};