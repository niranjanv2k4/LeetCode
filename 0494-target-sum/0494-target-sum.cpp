class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> mp;
        return recurse(target, nums, 0, mp);
    }
    long recurse(int target, vector<int>& nums, int idx, unordered_map<int, unordered_map<int, int>>& mp){
    if(idx == (int)nums.size()){
        return 0 == target;
    }
    if(mp.find(target) != mp.end() && mp[target].find(idx)!=mp[target].end()){
        return mp[target][idx];
    }
    
    int add = recurse(target + nums[idx], nums, idx + 1, mp);
    int sub = recurse(target - nums[idx], nums, idx + 1, mp);
    
    return mp[target][idx] = add + sub;
}
};