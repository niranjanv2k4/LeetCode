class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        recurse(nums, 0, temp, res);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void recurse(vector<int>& nums, int idx, vector<int>& temp,
                 set<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.insert(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            temp.push_back(nums[idx]);
            recurse(nums, idx + 1, temp, res);
            temp.pop_back();
            swap(nums[i], nums[idx]);
        }
    }
};