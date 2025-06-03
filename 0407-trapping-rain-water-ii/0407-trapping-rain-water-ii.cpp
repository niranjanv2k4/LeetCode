class Solution {
public:
    using Cell = tuple<int, int, int>;

    int trapRainWater(vector<vector<int>>& map) {

        int m = map[0].size(), n = map.size();
        if (m < 3 && n < 3)
            return 0;

        auto [minHeap, visited] = createHeap(map);
        vector<int> dir = {0, 1, 0, -1, 0};
        int res = 0, level = 0;

        while (!minHeap.empty()) {
            auto [height, r, c] = minHeap.top();
            minHeap.pop();
            level = max(level, height);
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (nr > n - 1 || nc > m - 1 || nr < 0 || nc < 0)
                    continue;
                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    if (map[nr][nc] < level) 
                        res += level - map[nr][nc];
                    minHeap.push({map[nr][nc], nr, nc});
                }
            }
        }

        return res;
    }

    pair<priority_queue<Cell, vector<Cell>, greater<Cell>>,
         vector<vector<bool>>>
    createHeap(vector<vector<int>>& map) {

        int m = map[0].size(), n = map.size();
        priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++) {
            visited[0][i] = visited[n - 1][i] = true;
            minHeap.push({map[0][i], 0, i});
            minHeap.push({map[n - 1][i], n - 1, i});
        }
        for (int i = 1; i < n; i++) {
            visited[i][0] = visited[i][m - 1] = true;
            minHeap.push({map[i][0], i, 0});
            minHeap.push({map[i][m - 1], i, m - 1});
        }

        return {minHeap, visited};
    }
};