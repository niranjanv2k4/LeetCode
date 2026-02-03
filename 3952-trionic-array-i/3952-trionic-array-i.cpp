class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int i = 1;
        bool flag1 = false, flag2 = false, flag3 = false;
        while (i < nums.size() && nums[i] > nums[i - 1]){
            i++;
            flag1 = true;
        }

        while (i < nums.size() && nums[i] < nums[i - 1]){
            i++;
            flag2 = true;
        }
        while (i < nums.size() && nums[i] > nums[i - 1]){
            i++;
            flag3 = true;
        }

        return i == nums.size() && flag1 && flag2 && flag3;
    }
};