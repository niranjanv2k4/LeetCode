class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int res = 0;
        for (int i = 0; i < edges.size() && n > k; i++) {

            int from = edges[i][0], to = edges[i][1];
            int parent_from = find(parent, from);
            int parent_to = find(parent, to);

            if (parent_from == parent_to)
                continue;

            n--;
            unionfind(parent, rank, parent_from, parent_to);
            res = max(res, edges[i][2]);
        }
        return res;
    }

    void unionfind(vector<int>& parent, vector<int>& rank, int par_from,
                   int par_to) {
        if (rank[par_from] < rank[par_to]) {
            parent[par_from] = par_to;
        } else if (rank[par_to] < rank[par_from]) {
            parent[par_to] = par_from;
        } else {
            parent[par_to] = par_from;
            rank[par_to]++;
        }
    }

    int find(vector<int>& parent, int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent, parent[u]);
    }
};