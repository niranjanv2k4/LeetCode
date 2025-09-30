class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> temp = nums;
            nums.resize(temp.size() - 1);
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = (temp[i] + temp[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};