class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> hash_map;
        for (int c : nums)
            hash_map[c]++;
        int max_len = 0;
        for (const auto& [key, value] : hash_map) {
            if (hash_map.find(key + 1)!=hash_map.end())
                max_len = max(max_len, value + hash_map[key + 1]);
        }
        return max_len;
    }
};