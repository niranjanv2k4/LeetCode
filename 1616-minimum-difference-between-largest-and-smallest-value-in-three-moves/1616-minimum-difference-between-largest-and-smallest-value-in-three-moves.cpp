class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 4)
            return 0;

        int res = INT_MAX;

        for (int i = 0; i < 4; i++) {
            res = min(res, nums[n - 1 - (3 - i)] - nums[i]);
        }
        
        return res;
    }
};