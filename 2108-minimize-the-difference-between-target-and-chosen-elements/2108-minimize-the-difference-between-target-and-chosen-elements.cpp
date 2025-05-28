class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5000> bs;
        bs[0] = 1;

        for (auto& row : mat) {
            bitset<5000> new_bs;
            for (int el : row) {
                new_bs |= (bs << el);
            }
            bs = new_bs;
        }

        int res = INT_MAX;
        for (int i = 0; i < 4900; i++) {
            if (bs[i]) {
                res = min(res, abs(target - i));
            }
        }
        return res;
    }
};