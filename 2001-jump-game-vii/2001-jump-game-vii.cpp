class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] == '1')
            return false;

        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0;
        
        for (int idx = 1; idx < n; idx++) {
            if (idx - minJump >= 0 && dp[idx - minJump])
                count++;

            if (idx - maxJump - 1 >= 0 && dp[idx - maxJump - 1])
                count--;

            if (s[idx] == '0' && count > 0)
                dp[idx] = true;
        }

        return dp[n - 1];
    }
};