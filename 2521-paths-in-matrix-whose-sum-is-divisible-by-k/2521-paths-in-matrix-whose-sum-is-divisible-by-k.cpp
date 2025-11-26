class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k, 0)));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(i == 1 && j == 1){
                    int rem = grid[i-1][j-1] % k;
                    dp[i][j][rem] = 1;
                }else{
                    for(int rem = 0; rem<k; rem++){
                        int prev = ((rem - grid[i-1][j-1])%k + k)%k;
                        dp[i][j][rem] = (dp[i-1][j][prev] + dp[i][j-1][prev])%(1000000007LL);
                    }
                }
            }
        }
        return dp[n][m][0];
    }

};