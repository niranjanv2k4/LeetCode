class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tot = accumulate(nums.begin() + 1, nums.end(), 0), curr = nums[0];
        int res = (tot - curr) % 2 == 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            res += (tot - curr) % 2 == 0;
            tot -= nums[i];
            curr += nums[i];
        }
        return res;
    }
};