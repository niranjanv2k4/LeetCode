class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int count = 0;
        for (int num : nums) {
            if (el == num)
                count++;
            else
                count--;
            if (count == 0){
                el = num;
                count = 1;
            }
        }
        return el;
    }
};