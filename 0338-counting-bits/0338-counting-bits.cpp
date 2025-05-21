class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        res[0] = 0;
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 2 * curr)
                curr *= 2;
            res[i] = res[i - curr] + 1;
        }
        return res;
    }
};