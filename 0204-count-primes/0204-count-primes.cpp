class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                for (int j = 2; j * i < n; j++) {
                    is_prime[j * i] = false;
                }
                res++;
            }
        }
        return res;
    }
};