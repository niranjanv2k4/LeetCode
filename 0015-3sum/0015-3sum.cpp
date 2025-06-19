class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, k = 0;
        vector<vector<int>> res;
        int n = nums.size();

        while (i < n) {
            j = i + 1;
            k = n - 1;
            int num_1 = nums[i];
            while (j < k) {
                if (num_1 + nums[j] + nums[k] > 0) {
                    k--;
                } else if (num_1 + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    int num_2 = nums[j], num_3 = nums[k];
                    j++;
                    k--;
                    while (j < k && nums[j] == num_2)
                        j++;
                    while (k > j && nums[k] == num_3)
                        k--;
                }
            }
            i++;
            while (i < n && nums[i] == num_1)
                i++;
        }

        return res;
    }
};