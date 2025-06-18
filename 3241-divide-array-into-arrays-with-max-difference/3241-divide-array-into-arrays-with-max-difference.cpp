class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp(3);
        int n = nums.size();

        temp[0] = nums[0];

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                if (temp[2] - temp[0] > k)
                    return {};
                res.push_back(temp);
                if (i == n)
                    break;
            }
            temp[i%3] = nums[i];
        }
        
        return res;
    }
};