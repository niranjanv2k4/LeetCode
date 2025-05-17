class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = 0, white = 0;
        for (int num : nums) {
            if (num == 0)
                red++;
            else if (num == 1)
                white++;
            else
                blue++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < red)
                nums[i] = 0;
            else if (i < red + white)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};