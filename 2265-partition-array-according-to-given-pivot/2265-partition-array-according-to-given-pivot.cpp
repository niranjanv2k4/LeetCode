class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        queue<int> l, g, e;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                l.push(nums[i]);
            } else if (nums[i] > pivot) {
                g.push(nums[i]);
            } else {
                e.push(nums[i]);
            }
        }

        nums.clear();

        while (!l.empty()) {
            nums.push_back(l.front());
            l.pop();
        }
        while (!e.empty()) {
            nums.push_back(e.front());
            e.pop();
        }
        while (!g.empty()) {
            nums.push_back(g.front());
            g.pop();
        }
        
        return nums;
    }
};