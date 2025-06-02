class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
            if (nums[i] == nums[j]) {
                while (j < n && nums[i] == nums[j])
                    j++;
                if (j == n)
                    return i + 1;
                nums[++i] = nums[j];
                continue;
            }
            i++;
            j++;
        }
        return i == 0 ? 1 : i + 1;
    }
};