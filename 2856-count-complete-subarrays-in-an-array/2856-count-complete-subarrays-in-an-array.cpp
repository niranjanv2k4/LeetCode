class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int c : nums) {
            map[c]++;
        }
        int size = map.size();
        map.clear();
        int n = nums.size(), count = 0, j = 0;
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
            while (map.size() >= size && j < n) {
                count += (n - i);
                map[nums[j]]--;
                if (map[nums[j]] == 0)
                    map.erase(nums[j]);
                j++;
            }
        }
        return count;
    }
};