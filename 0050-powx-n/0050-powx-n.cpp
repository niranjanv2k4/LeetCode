class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (x == -1)
            return n % 2 ? -1 : 1;
        if (x == 1)
            return 1;
        if (n == INT_MIN)
            return 0;
        int power = abs(n);
        while (power > 0) {
            if (power % 2 == 1)
                ans *= x;
            x *= x;
            power /= 2;
        }
        return n > 0 ? ans : (1 / ans);
    }
};