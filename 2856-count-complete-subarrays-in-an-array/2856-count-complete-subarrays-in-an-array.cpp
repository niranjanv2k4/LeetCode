class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_map<int, int> map;
        for (int c : nums) 
            map[c]++;

        int size = map.size(), n = nums.size();
        int count = 0, start = 0;
        map.clear();

        for (int i = 0; i < n; i++) {
            map[nums[i]]++;

            while (map.size() >= size) {
                count += (n - i);
                map[nums[start]]--;

                if (map[nums[start]] == 0)
                    map.erase(nums[start]);

                start++;
            }

        }
        return count;
    }
};