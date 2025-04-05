class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int sum = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            recurse(i + 1, 0, 0, 0, n, nums, sum);
        }
        return sum;
    }

    void recurse(int size, int currXor, int index, int currSize, int n,
                 vector<int> nums, int& sum) {
        if (currSize == size) {
            sum += currXor;
            return;
        }

        for (int i = index; i < n; i++) {
            recurse(size, currXor ^ nums[i], i + 1, currSize + 1, n, nums, sum);
        }
    }
};