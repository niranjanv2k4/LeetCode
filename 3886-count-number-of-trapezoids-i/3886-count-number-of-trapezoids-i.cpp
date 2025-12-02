class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        // int total = points.size();

        unordered_map<int, int> map;
        int max_val = 0;
        for (auto point : points) {
            map[point[1]]++;
            max_val = max(map[point[1]], max_val);
        }
        long long total = 0, sum = 0;
        for (auto [y, num] : map) {
            long long c = comb(num);
            total = (total + c) % MOD;
            sum = (sum + c * c % MOD) % MOD;
        }
        long long inv2 = (MOD + 1) / 2;
        long long res =
            ((total * total % MOD - sum + MOD) % MOD) * inv2 % MOD;
        return res;
    }

    long long comb(int n) {
        if (n < 2)
            return 0;
        long long inv2 = (MOD + 1) / 2;
        return (1LL * n * (n - 1) % MOD) * inv2 % MOD;
    }
};