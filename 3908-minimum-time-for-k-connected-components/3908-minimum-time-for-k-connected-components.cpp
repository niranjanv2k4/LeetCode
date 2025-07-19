class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] > b[2];
             });

        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        int i = 0;
        for (; i < edges.size() && n >= k; i++) {
            int from = edges[i][0], to = edges[i][1];
            int par_from = find(parent, from), par_to = find(parent, to);

            if (par_from != par_to) {
                unionfind(parent, rank, par_from, par_to);
                n--;
            }
        }

        return n < k ? edges[i - 1][2] : 0;
    }
    
    void unionfind(vector<int>& parent, vector<int>& rank, int u, int v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    int find(vector<int>& parent, int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent, parent[u]);
    }
};