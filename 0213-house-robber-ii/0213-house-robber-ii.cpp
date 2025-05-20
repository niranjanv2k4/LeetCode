class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> temp2(nums.begin(), nums.end() - 1);
        return max(maxVal(temp1), maxVal(temp2));
    }

    int maxVal(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int nonTake = prev;
            int curi = max(take, nonTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};