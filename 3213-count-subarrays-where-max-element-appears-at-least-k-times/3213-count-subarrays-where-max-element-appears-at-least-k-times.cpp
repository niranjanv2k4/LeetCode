class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        const int n = nums.size();
        const int maxEl = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int j = 0, count = 0;

        for (int i = 0; i < n; i++) {
            count += nums[i] == maxEl;
            while (count >= k) {
                result += (n - i);
                count -= nums[j++] == maxEl;
            }
        }

        return result;
    }
};