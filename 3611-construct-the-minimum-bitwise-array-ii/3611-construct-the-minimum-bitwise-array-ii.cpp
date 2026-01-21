class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int curr = 0;
            int scan = nums[i];
            int num = nums[i];

            if (num % 2 == 0) {
                res[i] = -1;
                continue;
            }

            while (scan & 1) {
                scan >>= 1;
                curr++;
            }

            res[i] = nums[i] - (1 << (curr - 1));
        }

        return res;
    }
};
