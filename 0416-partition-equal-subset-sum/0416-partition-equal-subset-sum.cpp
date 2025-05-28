class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        sum /= 2;

        bitset<100000> bs;
        bs[nums[0]] = bs[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            bs |= (bs << nums[i]);
        }
        return bs[sum];
    }
};