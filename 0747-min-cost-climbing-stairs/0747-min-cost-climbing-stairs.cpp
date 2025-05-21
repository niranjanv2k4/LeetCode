class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        int prev2 = cost[n - 2], prev1 = cost[n - 1], curr;

        for (int i = n - 3; i >= 1; i--) {
            curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        
        return min(curr, prev1+cost[0]);
    }
};