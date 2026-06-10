class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int size = 32 - __builtin_clz(n);

        vector<vector<int>> s_max(n, vector<int>(size));
        vector<vector<int>> s_min(n, vector<int>(size));

        for (int i = 0; i < n; i++) {
            s_max[i][0] = nums[i];
            s_min[i][0] = nums[i];
        }

        for (int j = 1; j < size; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                s_max[i][j] =
                    max(s_max[i][j - 1], s_max[i + (1 << (j - 1))][j - 1]);

                s_min[i][j] =
                    min(s_min[i][j - 1], s_min[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto get_max = [&](int l, int r) {
            int len = 31 - __builtin_clz(r - l + 1);
            return max(s_max[l][len], s_max[r - (1 << len) + 1][len]);
        };

        auto get_min = [&](int l, int r) {
            int len = 31 - __builtin_clz(r - l + 1);
            return min(s_min[l][len], s_min[r - (1 << len) + 1][len]);
        };

        priority_queue<tuple<int, int, int>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({get_max(l, n - 1) - get_min(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({get_max(l, r - 1) - get_min(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};