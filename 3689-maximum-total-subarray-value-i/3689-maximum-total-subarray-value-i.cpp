class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min_el = *min_element(nums.begin(), nums.end());
        long long max_el = *max_element(nums.begin(), nums.end());

        return (max_el - min_el) * k;
    }
};