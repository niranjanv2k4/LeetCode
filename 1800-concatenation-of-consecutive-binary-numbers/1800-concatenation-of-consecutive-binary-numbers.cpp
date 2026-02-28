class Solution {
public:
    int concatenatedBinary(int n) {

        long long int res = 0;
        int MOD = 1e9 + 7;

        for(int i = 1; i<=n; i++){
            int bits = 32 - __builtin_clz(i);
            res <<= bits;
            res = (res + i) % MOD;
        }

        return res;
    }
};