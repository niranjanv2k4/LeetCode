class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> map(37, 0);
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0, x = i;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            map[sum]++;
            maxSize = max(maxSize, map[sum]);
        }

        int result = 0;
        for (int c : map) {
            if (c == maxSize) result++;
        }
        return result;
    }
};
