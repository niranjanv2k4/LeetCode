class Solution {
public:
    bool isGood(vector<int>& nums) {
        int count = 0, n = nums.size() - 1;
        unordered_set<int> st;

        for (int el : nums) {
            if(el > n)
                return false;
            st.insert(el);
            if (el == n)
                count++;
        }
        return st.size() == nums.size() - 1 && count == 2;
    }
};