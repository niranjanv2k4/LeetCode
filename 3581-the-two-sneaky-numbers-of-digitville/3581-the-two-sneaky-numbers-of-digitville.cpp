class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int c:nums){
            mp[c]++;
            if(mp[c]>1){
                res.push_back(c);
            }
        }
        return res;
    }
};