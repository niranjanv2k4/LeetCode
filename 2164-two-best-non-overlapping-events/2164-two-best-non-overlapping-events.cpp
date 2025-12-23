class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int n = events.size();
        vector<int> next(n);
        vector<vector<int>> dp(n, vector<int>(3, -1));
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int h = n;
            while (l < h) {
                int m = (l + h) / 2;
                if (events[m][0] > events[i][1]) {
                    h = m;
                } else {
                    l = m + 1;
                }
            }
            next[i] = l;
        }
        return recurse(events, 0, 0, next, dp);
    }
    int recurse(vector<vector<int>>& events, int idx, int curr,
                vector<int>& next, vector<vector<int>>& dp) {
        if (idx == events.size() || curr == 2)
            return 0;

        if (dp[idx][curr] != -1)
            return dp[idx][curr];

        int take =
            recurse(events, next[idx], curr + 1, next, dp) + events[idx][2];
        int not_take = recurse(events, idx + 1, curr, next, dp);

        return dp[idx][curr] = max(take, not_take);
    }
};