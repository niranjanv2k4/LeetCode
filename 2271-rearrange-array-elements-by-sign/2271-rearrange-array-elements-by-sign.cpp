class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n);

        for (int i = 0, idx_1 = 0, idx_2 = 1; i < n; i++) {
            if (nums[i] >= 0) {
                res[idx_1] = nums[i];
                idx_1 += 2;
            } else {
                res[idx_2] = nums[i];
                idx_2 += 2;
            }
        }

        return res;
    }
};