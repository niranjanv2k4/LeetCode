class Solution {
public:
    using cell = tuple<int, int, int>;
    using pq = priority_queue<cell, vector<cell>, greater<cell>>;

    int trapRainWater(vector<vector<int>>& map) {

        const int n = map.size(), m = map[0].size();
        
        if (m < 3 || n < 3)
            return 0;

        auto [heap, visited] = createMap(map);
        vector<int> dir = {0, 1, 0, -1, 0};
        int level = 0, res = 0;

        while (!heap.empty()) {
            auto [height, r, c] = heap.top();
            heap.pop();
            level = max(level, height);
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (nr <= 0 || nc <= 0 || nr >= n || nc >= m)
                    continue;
                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    if (map[nr][nc] < level)
                        res += level - map[nr][nc];
                    heap.push({map[nr][nc], nr, nc});
                }
            }
        }

        return res;
    }

    pair<pq, vector<vector<bool>>> createMap(vector<vector<int>>& map) {

        int n = map.size(), m = map[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq heap;

        for (int i = 0; i < m; i++) {
            visited[0][i] = visited[n - 1][i] = true;
            heap.push({map[0][i], 0, i});
            heap.push({map[n - 1][i], n - 1, i});
        }
        for (int i = 1; i < n; i++) {
            visited[i][0] = visited[i][m - 1] = true;
            heap.push({map[i][0], i, 0});
            heap.push({map[i][m - 1], i, m - 1});
        }

        return {heap, visited};
    }
};