class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                if(idx>j){
                    res += (idx - j);
                }
            }
        }
        return res;
    }
};