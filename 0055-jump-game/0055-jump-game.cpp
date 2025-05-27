class Solution {
public:
    bool canJump(vector<int>& nums) {
        int final = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > final)
                return false;
            final = max(final, i + nums[i]);
        }
        return true;
    }
};