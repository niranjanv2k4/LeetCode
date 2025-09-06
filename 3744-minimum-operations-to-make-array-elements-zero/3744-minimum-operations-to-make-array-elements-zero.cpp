class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (auto query : queries) {
            res += (helper(query[1]) - helper(query[0] - 1) + 1) / 2;
        }
        return res;
    }

    long long helper(int num) {
        int lvl = 1, base = 1;
        long long count = 0;
        while (base <= num) {
            count +=
                (long long)((lvl + 1) / 2) * (min(base * 2 - 1, num) - base + 1);
            base *= 2;
            lvl++;
        }
        return count;
    }
};