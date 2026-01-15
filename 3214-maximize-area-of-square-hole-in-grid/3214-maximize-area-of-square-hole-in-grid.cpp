class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int horizontal = 1, curr = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            horizontal = max(horizontal, curr);
        }

        int vertical = 1;
        curr = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            vertical = max(vertical, curr);
        }

        int max_len = min(horizontal, vertical) + 1;
        return max_len * max_len;
    }
};
