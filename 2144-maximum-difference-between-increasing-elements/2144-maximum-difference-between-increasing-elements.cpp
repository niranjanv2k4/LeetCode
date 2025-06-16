class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff = -1, curr = INT_MAX;
        for (int num : nums) {
            if (curr >= num)
                curr = num;
            else
                max_diff = max(max_diff, num - curr);
        }
        return max_diff;
    }
};