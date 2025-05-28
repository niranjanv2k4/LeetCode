class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int val = INT_MAX;
        vector<vector<bool>> dp(mat.size(), vector<bool>(target+5000, false));
        int global= INT_MAX;
        vector<int> minRemaining(mat.size()+1, 0);
        for(int i = mat.size()-1; i>=0; i--){
            minRemaining[i] = (*min_element(mat[i].begin(), mat[i].end())) + minRemaining[i+1];

        }
        return recurse(mat, 0, target, 0, dp, global, minRemaining);
    }

    int recurse(vector<vector<int>>& mat, int idx, int target, int curr, vector<vector<bool>>& dp, int& global, vector<int>& minRemaining) {
        if (idx == mat.size()) {
            return global = abs(target-curr);
        }   
        if(curr>=dp[0].size())return INT_MAX;
        if(dp[idx][curr])return INT_MAX;
        dp[idx][curr]=true;
        // if(dp.count(idx) && dp[idx].count(curr))return dp[idx][curr];

        int minVal = INT_MAX, val;
        for (int i = 0; i < mat[idx].size(); i++) {
            val = recurse(mat, idx + 1, target, curr + mat[idx][i], dp, global, minRemaining);
            minVal = min(val, minVal);
        }
        return minVal;
    }
};