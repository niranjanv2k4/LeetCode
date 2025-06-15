class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos, neg;
        for (int num : nums) {
            if (num >= 0)
                pos.push(num);
            else
                neg.push(num);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i%2==0) {
                nums[i] = pos.front();
                pos.pop();
            } else {
                nums[i] = neg.front();
                neg.pop();
            }
        }
        return nums;
    }
};