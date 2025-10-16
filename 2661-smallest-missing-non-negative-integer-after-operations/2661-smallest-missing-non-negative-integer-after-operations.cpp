class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = ((nums[i] % value) + value) % value;
            mp[nums[i]]++;
        }

        vector<int> res(n);
        int idx = 0;

        for (auto [key, val] : mp) {
            while (val--) {
                res[idx++] = key + val * value;
            }
        }
        
        sort(res.begin(), res.end());

        if (res[0] != 0)
            return 0;

        for (int i = 1; i < res.size(); i++) {
            if (res[i] != res[i - 1] + 1)
                return res[i - 1] + 1;
        }

        return res[res.size() - 1] + 1;
    }
};