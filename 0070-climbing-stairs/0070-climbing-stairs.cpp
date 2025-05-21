class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 0, curr;
        for(int i = 0; i<n; i++){
             curr = prev1 + prev2;
             prev2 = prev1;
             prev1 = curr;
        }
        return curr;
    }
};