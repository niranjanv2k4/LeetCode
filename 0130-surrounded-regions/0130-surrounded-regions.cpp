class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<int> dir = {0, 1, 0, -1, 0};
        auto [q, visited] = create_queue(board);

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nc == m || nr == n)
                    continue;

                if (board[nr][nc] == 'O') {
                    if (!visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        update(board, visited);
    }

    void update(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int i = 1; i < visited.size() - 1; i++) {
            for (int j = 1; j < visited[0].size() - 1; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    pair<queue<pair<int, int>>, vector<vector<bool>>>
    create_queue(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                visited[0][i] = true;
            }
            if (board[n - 1][i] == 'O') {
                q.push({n - 1, i});
                visited[n - 1][i] = true;
            }
        }
        return {q, visited};
    }
};