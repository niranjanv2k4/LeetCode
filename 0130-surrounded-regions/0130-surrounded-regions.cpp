class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for (int i = 1; i < board.size() - 1; i++) {
            for (int j = 1; j < board[0].size() - 1; j++) {
                if (board[i][j] == 'O')
                    bfs(board, i, j);
            }
        }
    }

    void update(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int i = 1; i < visited.size() - 1; i++) {
            for (int j = 1; j < visited[0].size() - 1; j++) {
                if (visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int r, int c) {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dir = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;

        q.push({r, c});
        visited[r][c] = true;
        bool res = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nc == m || nr == n)
                    continue;

                if (board[nr][nc] == 'O') {
                    if ((nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1)) {
                        res = false;
                    }
                    if (!visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        if (res)
            update(board, visited);
    }
};