class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            bool flag = false;
            for(int num = 1; num < nums[i]; num++){
                if((num | num + 1) == nums[i]){
                    res[i] = num;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                res[i] = -1;
        }

        return res;
    }
};