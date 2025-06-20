class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n < 4)
            return {};

        vector<vector<int>> res;

        for (int a = 0; a < n - 3; a++) {

            if (a != 0 && nums[a] == nums[a - 1])
                continue;

            for (int i = a + 1; i < n - 2; i++) {
                if (i != a + 1 && nums[i] == nums[i - 1])
                    continue;

                int j = i + 1;
                int k = n - 1;

                while (j < k) {
                    long long num =
                        (long long)nums[a] + nums[i] + nums[j] + nums[k];
                    if (num > target) {
                        k--;
                    } else if (num < target) {
                        j++;
                    } else {
                        res.push_back({nums[a], nums[i], nums[j], nums[k]});
                        int num_2 = nums[j], num_3 = nums[k];
                        j++;
                        k--;
                        while (j < k && nums[j] == num_2)
                            j++;
                        while (k > j && nums[k] == num_3)
                            k--;
                    }
                }
            }
        }

        return res;
    }
};