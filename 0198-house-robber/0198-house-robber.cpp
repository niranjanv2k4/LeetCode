class Solution {
public:
    int rob(vector<int>& nums) {
        int take = nums[0];
        int not_take = 0;
        int max_val;

        for(int i = 1; i<nums.size(); i++){
            int max_val = max(take, not_take + nums[i]);
            not_take = take;
            take = max_val;
        }

        return max(take, not_take);
    }
};