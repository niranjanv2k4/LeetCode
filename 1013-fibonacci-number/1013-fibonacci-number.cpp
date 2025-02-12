class Solution {
public:
    int fib(int n) {
        if (n == 1)
            return 1;
        int prev = 0, curr = 1;
        int fib = 0;
        for (int i = 1; i < n; i++) {
            fib = curr + prev;
            prev = curr;
            curr = fib;
        }
        return fib;
    }
};