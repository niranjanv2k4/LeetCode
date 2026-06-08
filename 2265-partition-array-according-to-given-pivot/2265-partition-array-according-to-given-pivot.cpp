class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low, high;
        int same = 0;
        
        for (int el : nums) {
            if (el < pivot) {
                low.push_back(el);
            } else if (el > pivot)
                high.push_back(el);
            else
                same++;
        }

        vector<int> res(low.begin(), low.end());
        while (same--)
            res.push_back(pivot);

        for (int el : high)
            res.push_back(el);

        return res;
    }
};