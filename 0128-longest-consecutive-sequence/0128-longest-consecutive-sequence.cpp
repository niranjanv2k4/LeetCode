class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;

        for (int num : nums)
            s.insert(num);

        int res = 0;
        for (int x : s) {
            if (!s.count(x - 1)) {
                int count = 1, temp = x + 1;
                while (s.count(temp++)) {
                    count++;
                }
                res = max(res, count);
            }
        }
        
        return res;
    }
};