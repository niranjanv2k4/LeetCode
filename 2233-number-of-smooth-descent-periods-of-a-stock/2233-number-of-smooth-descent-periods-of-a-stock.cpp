class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        int curr = 1;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] - prices[i + 1] == 1) {
                curr++;
            } else {
                res += (1LL*curr * (curr + 1)) / 2;
                curr = 1;
            }
        }
        return res + (1LL*curr * (curr + 1)) / 2;
    }
};