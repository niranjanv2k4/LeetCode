class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_map<int, int> mp;
            for(int l = i; l<i+k; l++)mp[nums[l]]++;
            priority_queue<pair<int, int>> q;
            for (auto [key, value] : mp) {
                q.push({value, key});
            }
            int sum = 0;
            for (int j = 0; j < x && !q.empty(); j++) {
                sum += q.top().first*q.top().second;
                q.pop();
            }
            res.push_back(sum);
        }
        return res;
    }
};