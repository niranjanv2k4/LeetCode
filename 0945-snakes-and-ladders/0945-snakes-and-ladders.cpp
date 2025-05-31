class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) { return bfs(board); }

    int bfs(vector<vector<int>>& board) {

        const int n = board.size(), total = n * n;
        int k = 0;
        queue<int> q;
        vector<bool> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                if (node == n * n)
                    return k;
                int start = node + 1, end = node + 7;
                for (int i = start; i < end && i <= total; i++) {
                    auto [row, col] = getCoordinates(i, n);
                    if (!visited[i]) {
                        visited[i] = true;
                        q.push(board[row][col] == -1 ? i : board[row][col]);
                    }
                }
            }
            k++;
        }
        
        return -1;
    }

    pair<int, int> getCoordinates(int num, int n) {
        int row = (n - 1) - ((num - 1) / n);
        int col = (num - 1) % n;
        if (n % 2 == row % 2)
            col = (n - 1) - col;
        return {row, col};
    }
};