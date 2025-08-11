class Solution {
public:
    int countVowelPermutation(int n) {
        
        const int MOD = 1e9 + 7;
        int a = 1, e = 1, i = 1, o = 1, u = 1;

        for (int k = 2; k <= n; k++) {
            int na = e;
            int ne = ((long long)a + i) % MOD;
            int ni = ((long long)a + e + o + u) % MOD;
            int no = ((long long)u + i) % MOD;
            int nu = a;

            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }
        
        return ((long long)a+e+i+o+u)%MOD;
    }
};