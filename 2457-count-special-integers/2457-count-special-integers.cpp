class Solution {
public:
    int countSpecialNumbers(int n) { return count(0, 0, n) - 1; }
    int count(int mask, long long num, const int n) {
        if (num > n)
            return 0;

        long long total = 1;
        for (int i = 0; i < 10; i++) {
            if ((mask & (1 << i)) || (i == 0 && num == 0))
                continue;
            total += count(mask | (1 << i), num * 10 + i, n);
        }
        return total;
    }
};