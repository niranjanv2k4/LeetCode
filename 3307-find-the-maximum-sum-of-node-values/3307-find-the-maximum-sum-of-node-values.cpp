class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long ans = 0, discarded = INT_MAX, count = 0;

        for(int num:nums){
            ans += max(num, num^k);
            count += (num^k)>num;
            discarded = min(discarded, (long long)abs((num^k)-num));
        }
        
        return count%2?ans-discarded:ans;
    }
};