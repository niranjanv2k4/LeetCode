class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<long long, long long> mp;

        long long res = 0;
        for (int num : nums) {
            mp[num]++;
            res = max(res, mp[num]);
        }
        unordered_set<long long> unique;
        for (int num : nums) {
            unique.insert(num);
            unique.insert(num - k);
            unique.insert(num + k);
        }
        for (long long el :unique) {
            long long left =
                lower_bound(nums.begin(), nums.end(), el - k) - nums.begin();
            long long right = upper_bound(nums.begin(), nums.end(), el + k) -
                        nums.begin() - 1;

            long long temp = 0;
            if (mp.count(el)) {
                temp = min(right - left + 1, mp[el] + numOperations);
            } else {
                temp = min(right - left + 1, 1LL*numOperations);
            }
            res = max(res, temp);
        }

        return res;
    }
};
