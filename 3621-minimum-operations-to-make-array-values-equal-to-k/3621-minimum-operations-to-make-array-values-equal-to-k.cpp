class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0, n = nums.size();
        int prev = nums[n-1];

        if(nums[0]<k)return -1;
        
        for(int i = n - 1; i>=0; i--){
            if(nums[i]!=prev){
                count++;
                prev = nums[i];
            }
        }

        return nums[0]==k?count:count+1;
    }
};