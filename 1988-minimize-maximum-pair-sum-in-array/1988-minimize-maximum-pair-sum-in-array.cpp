class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int res = INT_MIN;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++)
            res = max(res, nums[i] + nums[n-i-1]);

        return res;
    }
};