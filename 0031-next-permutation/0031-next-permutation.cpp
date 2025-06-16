class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        vector<int> suffix(n, -1);
        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], nums[i]);
            if (nums[i] != suffix[i]) {
                int j = i + 1;
                while (j < n && suffix[j] > nums[i])
                    j++;
                swap(nums[i], nums[j - 1]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        
        reverse(nums.begin(), nums.end());
    }
};