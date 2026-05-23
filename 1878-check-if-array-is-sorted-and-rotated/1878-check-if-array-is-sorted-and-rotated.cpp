class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size(), idx = 0;

        for (int i = 0; i < n; i++) {
            rotate(nums);
            if(is_sorted(nums))
                return true;
        }

        return false;
    }

    void rotate(vector<int>& nums) {
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = temp;
    }

    bool is_sorted(vector<int>&  nums){
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] > nums[i])
                return false;
        }
        return true;
    }
};