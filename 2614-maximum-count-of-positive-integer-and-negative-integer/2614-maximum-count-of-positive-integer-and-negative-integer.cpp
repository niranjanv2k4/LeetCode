class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        int left = 0, right = nums.size() - 1;
        int n = nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] < 0) {
                neg = max(neg, mid + 1);
                left = mid + 1;
            } else if (nums[mid] > 0) {
                pos = max(pos, n - mid);
                right = mid - 1;
            } else {
                int i = mid;
                while (i >= 0 && nums[i] == 0)
                    i--;
                neg = i + 1;

                i = mid;
                while (i < n && nums[i] == 0)
                    i++;
                pos = n - i;

                break;
            }
        }
        return max(pos, neg);
    }
};