class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long low = -1e10, high = 1e10;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            for (int i = 0; i < nums1.size(); i++) {
                count += countNumbers(nums2, nums1[i], mid);
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    long long countNumbers(vector<int>& a, long long num, long long val) {
        int n1 = a.size();

        long long low = 0, high = n1 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((num >= 0 && num * a[mid] <= val) ||
                (num < 0 && num * a[mid] > val)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (num >= 0)
            return low;
        return n1 - low;
    }
};