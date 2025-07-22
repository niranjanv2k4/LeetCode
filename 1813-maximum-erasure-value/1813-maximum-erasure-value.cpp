class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        unordered_map<int, int> freq;
        int res = 0, sum = 0, j = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            sum += nums[i];
            for (; j < i && freq[nums[i]] > 1; j++) {
                sum -= nums[j];
                freq[nums[j]]--;
            }
            res = max(res, sum);
        }

        return res;
    }
};