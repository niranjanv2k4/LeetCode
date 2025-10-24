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
                if(i==0 || freq[j] == 0)continue;
                if (j != freq[j]) {
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