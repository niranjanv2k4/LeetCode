class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int count1 = 0, count2 = 0;
        for (int c : nums1) {
            if (c == 0)
                count1++;
            else
                sum1 += c;
        }
        for (int c : nums2) {
            if (c == 0)
                count2++;
            else
                sum2 += c;
        }
        if (sum2 > sum1) {
            if (count1 == 0 || (sum2 - sum1 < count1 && count2 == 0))
                return -1;
        } else if (sum1 > sum2) {
            if (count2 == 0 || (sum1 - sum2 < count2 && count1 == 0))
                return -1;
        } else if ((count1 > 0) ^ (count2 > 0)) {
            return -1;
        }
        return max(sum1 + count1, sum2 + count2);
    }
};