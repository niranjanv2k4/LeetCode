class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size(), prefix = 1;
        vector<int> suffix(n, 1), res(n);

        res[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; i--) 
            res[i] = res[i + 1] * nums[i];

        for(int i = 0; i<n-1; i++){
            res[i]=res[i+1]*prefix;
            prefix *= nums[i];
        }

        res[n-1]=prefix;
        
        return res;
    }
};