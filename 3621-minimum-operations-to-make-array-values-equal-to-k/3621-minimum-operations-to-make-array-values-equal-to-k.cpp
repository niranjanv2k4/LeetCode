class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (int c : nums) {
            s.insert(c);
        }
        int min = *s.begin();
        if (min < k)
            return -1;
        return min == k ? s.size() - 1 : s.size();
    }
};