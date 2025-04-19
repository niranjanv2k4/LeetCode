class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long l = search(nums, i + 1, lower - nums[i]);
            long long r = search(nums, i + 1, upper - nums[i] + 1);
            if (l != -1 && r != -1)
                count = count + r - l;
        }
        return count;
    }

    long long search(vector<int>& nums, int idx, int boundary) {

        int l = idx, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < boundary) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};