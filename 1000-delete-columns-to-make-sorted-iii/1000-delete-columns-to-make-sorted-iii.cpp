class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> dp(n, 1);
        for(int i = n - 2; i>=0; i--){
            for(int j = i+1; j<n; j++){
                bool flag = false;
                for(string str:strs){
                    if(str[i] > str[j]){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    continue;
                }else{
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};