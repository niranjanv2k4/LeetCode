class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int curr = 0, n = nums.size();
        nums.push_back(0);
        for(int i = n-1; i>=1; i--)
            nums[i] -= nums[i-1];
        
        for (auto& query : queries) {
            nums[query[0]]--;
            nums[query[1]+1]++;
        }

        for (int i = 0; i < n-1; i++) 
            nums[i+1] += nums[i];
            
        return all_of(nums.begin(), nums.end()-1, [](int x) { return x <= 0; });
    }
};