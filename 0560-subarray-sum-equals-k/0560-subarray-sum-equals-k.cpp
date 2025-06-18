class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int prefix_sum = 0, res = 0;
        for (int num : nums) {
            prefix_sum += num;
            if (map.count(prefix_sum - k)) {
                res += map[prefix_sum-k];
            }
            map[prefix_sum]++;
        }
        return res;
    }
};