class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        if (restrictions.size() == 0)
            return n - 1;
        restrictions.push_back({1, 0});
        int m = restrictions.size();

        sort(restrictions.begin(), restrictions.end());
        if (restrictions[m - 1][0] != n) {
            restrictions.push_back({n, n - 1});
            m = restrictions.size();
        }

        for (int i = 1; i < m; i++) {
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] +
                                            restrictions[i][0] -
                                            restrictions[i - 1][0]);
        }

        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] +
                                            restrictions[i + 1][0] -
                                            restrictions[i][0]);
        }

        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            int best = ((restrictions[i + 1][0] - restrictions[i][0]) +
                        restrictions[i][1] + restrictions[i + 1][1]) /
                       2;
            res = max(res, best);
        }

        return res;
    }
};