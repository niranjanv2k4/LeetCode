class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(!vis[i][j] &&  grid[i][j] == '1'){
                    bfs(grid, i, j, vis);
                    res++;
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dir = {-1, 0, 1, 0, -1};

        vis[i][j] = true;

        while(!q.empty()){
            pair loc = q.front();
            q.pop();

            for(int i = 0; i<4; i++){

                int nr = loc.first + dir[i];
                int nc = loc.second + dir[i+1];

                if(nr < 0 || nc < 0 || nr == grid.size() || nc == grid[0].size() || vis[nr][nc] || grid[nr][nc] == '0')
                    continue;
                
                q.push({nr, nc});
                vis[nr][nc] = true;
            }
        }
    }
};