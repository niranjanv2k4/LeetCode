class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int res = 0;
        vector<int> dp(arr.size(), -1);
        for(int i = 0; i<arr.size(); i++){
            res = max(res, 1 + recurse(arr, d, i, dp));
        }


        return res;
    }

    int recurse(vector<int>& arr, int d, int idx, vector<int>& dp){

        if(dp[idx] != -1)
            return dp[idx];

        int res = 0;

        for(int i = idx - 1; i >= 0 && i >= idx - d && arr[i] < arr[idx]; i--){
            res = max(res, 1 + recurse(arr, d, i, dp));
        }

        for(int i = idx + 1; i < arr.size() && i <= idx + d && arr[i] < arr[idx]; i++){
           res = max(res, 1 + recurse(arr, d, i, dp));
        }

        return dp[idx] = res;
    }
};