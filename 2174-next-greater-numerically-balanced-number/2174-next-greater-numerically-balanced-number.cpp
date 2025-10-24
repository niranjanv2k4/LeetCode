class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            int temp = i;
            bool flag = true;
            vector<int> freq(10, 0);
            while (temp) {
                int rem = temp % 10;
                temp /= 10;
                freq[rem]++;
            }
            for (int j = 0; j < 10; j++) {
                if (j != freq[j] && freq[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};