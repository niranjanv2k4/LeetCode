class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        int g = 0;
        for (int num : nums) {
            if (num == 1)
                return n - count(nums.begin(), nums.end(), 1);
            g = gcd(g, num);
            flag &= (g != 1);
        }
        if (flag)
            return -1;

        int res = INT_MAX;

        for (int size = 1; size <= n; size++) {
            for (int start = 0; start + size <= n; start++) {
                int end = start + size - 1;
                int g = 0;
                for (int i = start; i <= end; i++) {
                    g = gcd(g, nums[i]);
                }
                if (g == 1) {
                    res = min(res, size + n - 2);
                }
            }
        }
        return res;
    }
};