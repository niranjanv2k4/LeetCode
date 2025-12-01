class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        if (m < n)
            return 0;
        sort(batteries.begin(), batteries.end());
        vector<long long> live(batteries.end() - n, batteries.end());
        long long extra = accumulate(batteries.begin(), batteries.end()-n, (long long)0);

        for (int i = 0; i < n - 1; i++) {
            if ((i + 1) * (live[i + 1] - live[i]) <= extra) {
                extra -= (i + 1) * (live[i + 1] - live[i]);
            } else
                return live[i] + extra / (i + 1);
        }

        return live[n - 1] + extra / n;
    }
};