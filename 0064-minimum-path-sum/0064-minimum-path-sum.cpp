class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        const int n = grid.size(), m= grid[0].size();
        vector<int> row(m);
        row[0]=grid[0][0];

        for(int i = 1; i<m; i++)
            row[i]=grid[0][i]+row[i-1];
        
        for(int i = 1; i<n; i++){
            row[0] += grid[i][0];
            for(int j = 1; j<m; j++)
                row[j]=grid[i][j]+min(row[j], row[j-1]);
        }
            
        return row[m-1];
    }
};