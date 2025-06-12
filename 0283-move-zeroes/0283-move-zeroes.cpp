class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0, n = nums.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                nums[idx++] = nums[i];
            else
                k++;
        }

        fill(nums.begin() + (n - k), nums.end(), 0);
    }
};