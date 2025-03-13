class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> rangeD(nums.size(), 0);
        int curr = 0, n = nums.size();

        for (auto& query : queries) {
            rangeD[query[0]] -= 1;
            if (query[1] + 1 < nums.size()) {
                rangeD[query[1] + 1] += 1;
            }
        }

        for (int i = 0; i < n; i++) {
            curr += rangeD[i];
            nums[i] += curr;
        }
        return all_of(nums.begin(), nums.end(), [](int x) { return x <= 0; });
    }
};