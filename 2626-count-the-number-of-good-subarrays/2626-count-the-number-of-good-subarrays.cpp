class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        unordered_map<int, int> map;
        long long count = 0, curr = 0, j = 0;

        for (int i = 0; i < nums.size(); i++) {
            curr += map[nums[i]];
            map[nums[i]]++;
            while (curr >= k) {
                count += nums.size() - i;
                curr -= --map[nums[j++]];
            }
        }
        
        return count;
    }
};