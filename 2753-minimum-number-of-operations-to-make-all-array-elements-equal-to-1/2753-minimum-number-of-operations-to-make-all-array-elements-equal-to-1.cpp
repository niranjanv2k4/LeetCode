class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        int g = 0;
        for (int num : nums) {
            if (num == 1)
                return n - count(nums.begin(), nums.end(), 1);
            g = gcd(g, num);
            flag &= (g != 1);
        }
        if (flag)
            return -1;

        int res = INT_MAX;

        for(int i = 0; i<n; i++){
            int g = nums[i];
            for(int j = i; j<n; j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    res = min(res, j - i + n - 1);
                }
            }
        }
        return res;
    }
};