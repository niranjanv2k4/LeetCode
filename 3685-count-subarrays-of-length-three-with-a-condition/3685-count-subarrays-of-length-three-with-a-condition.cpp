class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0, n = nums.size();
        
        for (int i = 1; i < n - 1; i++) 
            if (nums[i - 1] + nums[i + 1] == (float)nums[i] / 2) 
                count++;
        
        return count;
    }
};