class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> mini, maxi;
        int j = 0;

        for (int i = 0; i < n; i++) {

            while (!mini.empty() && nums[mini.back()] >= nums[i]) {
                mini.pop_back();
            }
            mini.push_back(i);

            while (!maxi.empty() && nums[maxi.back()] <= nums[i]) {
                maxi.pop_back();
            }
            maxi.push_back(i);

            while (!mini.empty() && !maxi.empty() &&
                   nums[maxi.front()] - nums[mini.front()] > k) {
                if (mini.front() == j)
                    mini.pop_front();
                if (maxi.front() == j)
                    maxi.pop_front();
                j++;
            }

            dp[i + 1] = pref[i];
            if (j > 0)
                dp[i + 1] = (dp[i + 1] - pref[j - 1] + MOD) % MOD;

            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};
