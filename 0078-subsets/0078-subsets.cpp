class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        generate(nums, 0, temp, res);
        return res;
    }
    void generate(vector<int>& nums, int idx, vector<int>& temp,
                  vector<vector<int>>& res) {
        res.push_back(temp);
        if (idx == nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            generate(nums, i + 1, temp, res);
            temp.pop_back();
        }
    }
};