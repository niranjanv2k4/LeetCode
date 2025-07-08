class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return recurse(events, k, 0, dp);
    }
    
    int recurse(vector<vector<int>>& events, int k, int idx,
                vector<vector<int>>& dp) {
        if (idx == events.size() || k == 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int take = events[idx][2];
        int not_take = recurse(events, k, idx + 1, dp);

        int next_idx = find_idx(events, idx);
        if (next_idx != events.size()) {
            take += recurse(events, k - 1, next_idx, dp);
        }

        return dp[idx][k] = max(take, not_take);
    }

    int find_idx(vector<vector<int>>& events, int idx) {

        int left = idx + 1;
        int right = events.size() - 1;
        int ans = events.size();

        while (left <= right) {
            int mid = right + (left - right) / 2;
            if (events[mid][0] <= events[idx][1]) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }

        return ans;
    }
};
