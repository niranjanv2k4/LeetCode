class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), bestIdx = 0;
        vector<int> dp(n, -1), maxLen(n, 1), temp, result;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (maxLen[j] >= maxLen[i]) {
                        dp[i] = j;
                        maxLen[i] = maxLen[j] + 1;
                        bestIdx = maxLen[i] > maxLen[bestIdx] ? i : bestIdx;
                    }
                }
            }
        }

        while (bestIdx != -1) {
            result.push_back(nums[bestIdx]);
            bestIdx = dp[bestIdx];
        }
        return result;
    }
};