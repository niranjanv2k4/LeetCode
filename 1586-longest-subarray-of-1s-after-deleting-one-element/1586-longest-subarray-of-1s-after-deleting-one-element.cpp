class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int res = 0, count = 0, j = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] == 0;
            while (count > 1 && j <= i) 
                count -= nums[j++] == 0;
            
            res = max(res, i - j);
        }

        return res;
    }
};