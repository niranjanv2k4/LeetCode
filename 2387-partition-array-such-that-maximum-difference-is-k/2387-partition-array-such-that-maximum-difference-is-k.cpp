class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();
        int res = 1, prev = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] - prev > k) {
                prev = nums[i];
                res++;
            }
        }
        
        return res;
    }
};
