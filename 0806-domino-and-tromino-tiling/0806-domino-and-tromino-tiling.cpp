class Solution {
public:
    int numTilings(int n) {
        if (n == 2)
            return 2;
        if (n == 1)
            return 1;
        long long prev1 = 5, prev2 = 2, prev3 = 1, curr;
        for (int i = 4; i <= n; i++) {
            curr = (2 * prev1 + prev3) % 1000000007;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};