class Solution {
public:
    int zigZagArrays(int n, int l, int r) {

        vector<int> dp0(r + 1, 0), dp1(r + 1, 0);
        vector<int> ndp0(r + 1, 0), ndp1(r + 1, 0);
        vector<int> pref(r + 1, 0), suff(r + 2, 0);
        const int MOD = 1e9 + 7;

        for (int el = l; el <= r; el++) {
            dp0[el] = 1;
            dp1[el] = 1;
        }

        for (int len = 1; len <= n - 1; len++) {

            pref[l] = dp1[l];
            for (int el = l + 1; el <= r; el++) {
                pref[el] = (pref[el - 1] + dp1[el]) % MOD;
            }

            suff[r] = dp0[r];
            for (int el = r - 1; el >= l; el--) {
                suff[el] = (suff[el + 1] + dp0[el]) % MOD;
            }

            for (int el = l; el <= r; el++) {
                ndp1[el] = (el < r) ? suff[el + 1] : 0;
                ndp0[el] = (el > l) ? pref[el - 1] : 0;
            }

            swap(dp0, ndp0);
            swap(dp1, ndp1);
        }

        int res = 0;
        for (int el = l; el <= r; el++)
            res = (res + (dp0[el] + dp1[el]) % MOD) % MOD;

        return res;
    }
};