class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();

        vector<long long> suffix(n, 0);
        vector<long long> prefix(n, 0);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1; i< n; i++){
            prefix[i] = max(prefix[i-1], (long long)nums[i]);
            suffix[n-1-i] = max(suffix[n-1-i+1], (long long)nums[n-1-i]);
        }

        for(int i = 1; i<n-1; i++){
            long long val = (long long)(prefix[i - 1]*suffix[i+1]) - (long long)(nums[i]*suffix[i+1]);
            result = val>result?val:result;
        }
        return result;
    }
};