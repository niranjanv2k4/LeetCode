class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = intervals.size();
        vector<int> todo(n, 2);
        int ans = 0;

        for (int t = n - 1; t >= 0; t--) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];

            for (int p = s; p < s + m; p++) {
                for (int i = 0; i <= t; i++) {
                    if (todo[i] > 0 && p <= intervals[i][1])
                        todo[i]--;
                }
                ans++;
            }
        }
        return ans;
    }
};
