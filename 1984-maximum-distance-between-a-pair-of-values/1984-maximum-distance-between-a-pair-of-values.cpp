class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int temp = search(i, nums2.size() - 1, nums2, nums1[i]);
            if (temp != -1 && temp - i > res) {
                cout << temp;
                res = temp - i;
            }
        }
        return res;
    }

    int search(int start, int end, vector<int>& nums, int val) {
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < val) {
                end = mid - 1;
            } else {
                res = mid;
                start = mid + 1;
            }
        }
        return res;
    }
};