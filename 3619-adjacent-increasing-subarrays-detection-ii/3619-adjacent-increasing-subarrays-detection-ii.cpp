class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res = 1;
        int c1 = 1, c2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                c1++;
            } else {
                c2 = c1;
                c1 = 1;
            }

            res = max(res, c1 / 2);
            res = max(res, min(c1, c2));
        }
        return res;
    }
};