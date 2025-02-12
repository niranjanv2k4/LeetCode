class Solution {
public:
    int tribonacci(int n) {
        if (n == 2 || n==1)
            return 1;
        if (n == 0)
            return 0;

        int fib = 2, curr = 1, prev1 = 1, prev2 = 0;
        for (int i = 2; i < n; i++) {
            fib = curr + prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
            curr = fib;
        }
        return fib;
    }
};