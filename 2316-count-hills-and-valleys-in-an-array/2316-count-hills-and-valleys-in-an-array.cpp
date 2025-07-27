class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0, i = 1;
        while (i < nums.size() - 1) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i])
                j++;
            if (j == nums.size()) break;

            if (nums[i] > nums[i - 1] && nums[i] > nums[j])
                res++;
            else if (nums[i] < nums[i - 1] && nums[i] < nums[j])
                res++;

            i = j;
        }
        return res;

    }
};