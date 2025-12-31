class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return;

        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int top = n, bottom = n + 1;

        vector<int> parent(n + 2), rank(n + 2, 0);
        for (int i = 0; i < n + 2; i++) parent[i] = i;

        vector<vector<bool>> land(row, vector<bool>(col, false));
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int i = cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            land[r][c] = true;

            int id = r * col + c;

            if (r == 0) unite(id, top, parent, rank);
            if (r == row - 1) unite(id, bottom, parent, rank);

            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d];
                int nc = c + dir[d + 1];
                if (nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
                if (!land[nr][nc]) continue;
                unite(id, nr * col + nc, parent, rank);
            }

            if (find(top, parent) == find(bottom, parent))
                return i;
        }
        return 0;
    }
};
