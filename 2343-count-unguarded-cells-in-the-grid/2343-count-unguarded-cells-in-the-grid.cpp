class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) { 
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<bool>> guard(m, vector<bool>(n, false));
        vector<vector<bool>> wall(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int res = 0;

        for (auto temp : guards) {
            vis[temp[0]][temp[1]] = guard[temp[0]][temp[1]] = true;
        }
        for (auto temp : walls) {
            wall[temp[0]][temp[1]] = true;
        }

        for (int r = 0; r < m; r++) {               
            for (int c = 0; c < n; c++) {           
                if (guard[r][c]) {                  
                    for (int i = r + 1; i < m; i++) {
                        if (wall[i][c] || guard[i][c])
                            break;
                        vis[i][c] = true;
                    }
                    for (int i = r - 1; i >= 0; i--) {
                        if (wall[i][c] || guard[i][c])
                            break;
                        vis[i][c] = true;
                    }
                    for (int i = c + 1; i < n; i++) {
                        if (wall[r][i] || guard[r][i])
                            break;
                        vis[r][i] = true;
                    }
                    for (int i = c - 1; i >= 0; i--) {
                        if (wall[r][i] || guard[r][i])
                            break;
                        vis[r][i] = true;
                    }
                }                                   
            }                                       
        }   
        
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if (!vis[r][c] && !wall[r][c]) {
                    res++;
                }
            }
        }                                        
        return res;
    }                                               
};                                                  
