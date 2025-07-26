class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];
                    if (nr < 0 || nc < 0 || nr == n || nc == m) 
                        continue;
                    
                    if (maze[nr][nc] == '.') {
                        if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1)
                            return steps;
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};