class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        bool flag = true;
        int num1 = -1, num2 = -1, prev = -1, curr = -1;
        int min = INT_MAX;

        for (int i = left == 1 ? 2 : left; i <= right; i++) {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                prev = curr;
                curr = i;
                if (prev != -1 && curr - prev < min) {
                    min = curr - prev;
                    num1 = prev;
                    num2 = curr;
                }
            }
            flag = true;
        }
        
        if (num1 == -1)
            return {-1, -1};
        return {num1, num2};
    }
};