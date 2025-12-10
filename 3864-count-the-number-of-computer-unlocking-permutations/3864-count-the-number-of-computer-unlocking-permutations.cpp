class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int n = complexity.size();
        vector<int> fac(n);
        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = 1LL * i * fac[i - 1] % MOD;
            if (complexity[i] <= complexity[0])
                return 0;
        }

        return fac[n - 1];
    }
};