class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return recurse(nums, 0, -1, dp);
    }

    int recurse(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp){
        if(idx == nums.size())
            return 0;
        
        if(prev != -1 && dp[idx][prev]  != -1)
            return dp[idx][prev];
        
        int take = 0;
        if(prev == -1 || nums[idx]  > nums[prev])
            take = 1 + recurse(nums, idx + 1, idx, dp);
        
        int not_take = recurse(nums, idx + 1, prev, dp);

        if(prev != -1)
            return dp[idx][prev]  = max(take, not_take);

        return max(take, not_take);
    }
};