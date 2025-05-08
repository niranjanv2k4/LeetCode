class Solution {
public:
    using state = tuple<int, int, int, bool>;

    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<state, vector<state>, greater<>> pq;
        vector<int> dir = {0, 1, 0, -1, 0};

        dist[0][0] = max(0, grid[0][0]);
        pq.emplace(0, 0, 0, true);

        while (!pq.empty()) {

            auto [time, row, col, flag] = pq.top();
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return time;
                
            for (int d = 0; d < 4; d++) {

                int nr = row + dir[d], nc = col + dir[d + 1];
                if (nr >= m || nc >= n || nr < 0 || nc < 0)
                    continue;

                int wait = max(grid[nr][nc], time) + (flag ? 1 : 2);
                if (wait < dist[nr][nc]) {
                    dist[nr][nc] = wait;
                    pq.emplace(wait, nr, nc, !flag);
                }
            }
        }
        return -1;
    }
};