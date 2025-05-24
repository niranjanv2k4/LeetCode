class Solution {
public:
    vector<vector<int>> pre;
    int dp[1 << 8];
    int m, n;
    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();
        vector<bool> selected(n, false);
        pre = vector<vector<int>>(n, vector<int>(n));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                for (int k = 0; k < m; k++) 
                    if (students[i][k] == mentors[j][k])
                        pre[i][j]++;
                

        return recurse(0, selected);
    }

    int recurse(int idx, vector<bool>& selected) {
        if (idx == n)
            return 0;

        int maxVal = 0;
        for (int i = idx; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (selected[j])
                    continue;
                selected[j] = true;
                maxVal = max(maxVal, recurse(i+1, selected) + pre[i][j]);
                selected[j] = false;
            }
        }
        return maxVal;
    }
};