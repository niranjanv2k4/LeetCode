class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pref(n + 1, 0), suff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (customers[i] == 'N');
        }

        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + (customers[i] == 'Y');
        }

        int min_pen = INT_MAX, res = 0, curr = 0;
        for (int i = 0; i <= n; i++) {
            if (pref[i] + suff[i] < min_pen) {
                min_pen = pref[i] + suff[i];
                res = i;
            }
        }

        return res;
    }
};
