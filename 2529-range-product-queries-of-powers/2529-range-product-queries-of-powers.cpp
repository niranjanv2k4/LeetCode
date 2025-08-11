class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> arr;
        int temp = 1;
        while (n > 0) {
            if (n & 1)
                arr.push_back(temp);
            temp *= 2;
            n = (n >> 1);
        }

        for (int i = 1; i < arr.size(); i++) {
            arr[i] = ((long long)arr[i] * arr[i - 1]) % MOD;
            cout << arr[i] << " ";
        }
        int size = queries.size();
        vector<int> res(size);
        for (int i = 0; i < size; i++) {
            int start = queries[i][0], end = queries[i][1];
            res[i] =
                start == 0
                    ? arr[end]
                    : (arr[end] * modpow(arr[start - 1], MOD - 2, MOD)) % MOD;
        }
        return res;
    }
    long long modpow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};