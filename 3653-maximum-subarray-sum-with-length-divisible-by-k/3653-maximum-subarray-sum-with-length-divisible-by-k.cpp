class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = LLONG_MIN;
        vector<long long> min_mod(k, LLONG_MAX); 

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        min_mod[0] = 0;
        for (int i = 1; i <= n; i++) {
            int mod = i % k;
            if (min_mod[mod] != LLONG_MAX) {
                res = max(res, pref[i] - min_mod[mod]);
            }
            min_mod[mod] = min(min_mod[mod], pref[i]);
        }

        return res;
    }
};