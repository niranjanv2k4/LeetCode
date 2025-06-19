class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        int count_1 = 0, count_2 = 0;
        int el_1 = INT_MIN, el_2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (count_1 == 0 && nums[i]!=el_2) {
                count_1 = 1;
                el_1 = nums[i];
            } else if (count_2 == 0 && nums[i]!=el_1) {
                count_2 = 1;
                el_2 = nums[i];
            } else if (nums[i] == el_1) {
                count_1++;
            } else if (nums[i] == el_2) {
                count_2++;
            } else {
                count_1--;
                count_2--;
            }
        }
        
        count_1 = count_2 = 0;
        vector<int> res;

        for (int c : nums) {
            count_1 += (c == el_1);
            count_2 += (c == el_2);
        }

        if (count_1 > n / 3)
            res.push_back(el_1);
        if (count_2 > n / 3)
            res.push_back(el_2);

        return res;
    }
};