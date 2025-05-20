class Solution {
public:
    int maxJump(vector<int>& stones) {
        const int n = stones.size();
        int result = stones[1] - stones[0];
        for (int i = 0; i < n - 2; i += 2) {
            result = max(result, stones[i + 2] - stones[i]);
            result = max(result, stones[i + 3] - stones[i + 1]);
        }
        return result;
    }
};