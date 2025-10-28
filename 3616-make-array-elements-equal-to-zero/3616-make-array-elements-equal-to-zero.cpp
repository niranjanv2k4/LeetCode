class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                for (int dir : {-1, 1}) {
                    res += simulate(nums, dir, i);
                }
            }
        }

        return res;
    }
    bool simulate(vector<int> nums, int dir, int i) {
        
        for (i; i < nums.size() && i >= 0; i += dir) {
            if (nums[i] > 0) {
                nums[i]--;
                dir *= -1;
            }
        }

        return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }
};