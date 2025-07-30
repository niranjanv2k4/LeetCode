class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = nums[0];
        int n = nums.size();
        int res = 0, i = 0;

        for (int i = 0; i < n; i++)
            max_val = max(max_val, nums[i]);

        while (i < n) {
            if (nums[i] == max_val) {
                int j = i - 1;
                while (j >= 0 && (nums[j] & max_val) == max_val) {
                    j--;
                }
                j++;
                int k = i + 1;
                while (k < n && (nums[k] & max_val) == max_val) {
                    k++;
                }
                res = max(res, k - j);
                i = k;
            } else
                i++;
        }

        return res;
    }
};