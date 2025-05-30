class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int curr = 0, j = 0;
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            curr += nums[i];
            while (curr >= target && j < n) {
                res = min(res, i - j + 1);
                curr -= nums[j++];
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};