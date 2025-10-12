class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> nums;
    unordered_map<long long, int> dp;

    long long encode(long long mask, int m, int k, int i) {
        return (((mask * 101 + m) * 101 + k) * 101 + i);
    }

    int recurse(long long mask, int m, int k, int i) {
        if (m == 0 && __builtin_popcountll(mask) == k)
            return 1;
        if (m == 0 || i == nums.size())
            return 0;

        long long key = encode(mask, m, k, i);
        if (dp.count(key))
            return dp[key];

        long long total = 0;

        total = (total + recurse(mask >> 1, m, k - (mask & 1), i + 1)) % MOD;

        for (int freq = 1; freq <= m; freq++) {
            long long nmask = mask + freq;
            int next = recurse(nmask >> 1, m - freq, k - (nmask & 1), i + 1);
            long long curr = 1;
            for (int p = 0; p < freq; p++)
                curr = (curr * nums[i]) % MOD;

            long long comb = 1;
            for (int x = 0; x < freq; x++)
                comb = (comb * (m - x)) % MOD;
            for (int x = 1; x <= freq; x++)
                comb = (comb * modInverse(x, MOD)) % MOD;

            total = (total + curr * 1LL * next % MOD * comb % MOD) % MOD;
        }

        return dp[key] = total;
    }

    long long modPow(long long a, long long b, int mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, int mod) {
        return modPow(a, mod - 2, mod);
    }

    int magicalSum(int m, int k, vector<int>& numsInput) {
        nums = numsInput;
        dp.clear();
        return recurse(0, m, k, 0);
    }
};
