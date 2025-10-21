class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;

        int res = 0;
        for (int num : nums) {
            mp[num]++;
            res = max(res, mp[num]);
        }

        for (int i = nums[0]; i <= nums[n - 1]; i++) {
            int left =
                lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
            int right =
                upper_bound(nums.begin(), nums.end(), i + k) - nums.begin() - 1;

            int temp = 0;
            if (mp.count(i)) {
                temp = min(right - left + 1, mp[i] + numOperations);
            } else {
                temp = min(right - left + 1, numOperations);
            }
            res = max(res, temp);
        }

        return res;
    }
};
