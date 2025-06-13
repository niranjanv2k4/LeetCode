class Solution {
public:
    int validPairs(vector<int>& nums, int maxVal) {
        int left = 0;
        int count = 0;
        while (left < nums.size() - 1) {
            if (nums[left + 1] - nums[left] <= maxVal) {
                count++;
                left++;
            }
            left++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int n = nums.size();
        int right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (validPairs(nums, mid) < p) {
                left = mid + 1;
            } else
                right = mid;
        }
        return left;
    }
};