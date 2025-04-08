class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> map(n);
        int i = n - 1;
        
        for (i; i >= 0; i--) {
            map[nums[i]]++;
            if (map[nums[i]] == 2)
                break;
        }

        return (i + 3) / 3;
    }
};