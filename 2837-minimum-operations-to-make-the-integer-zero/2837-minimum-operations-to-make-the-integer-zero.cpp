class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int res = 0;
        for (int i = 1; i < 60; i++) {
            long long temp = num1 - (long long)num2 * i;
            if (temp < i)
                return -1;
            if (i >= __builtin_popcountll(temp))
                return i;
        }
        return -1;
    }
};