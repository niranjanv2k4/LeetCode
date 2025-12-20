class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        vector<bool> dlt(strs[0].size(), false);
        for (int j = 0; j < strs[0].size(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    dlt[j] = true;
                    break;
                }
            }
        }
        return count_if(dlt.begin(), dlt.end(), [](int x) { return x; });
    }
};