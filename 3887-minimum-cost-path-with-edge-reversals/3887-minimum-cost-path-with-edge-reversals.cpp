class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        auto adj = createAdj(edges, n);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        q.push({0, 0});

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (d > dist[u])
                continue;

            for (auto [weight, v] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    q.push({dist[v], v});
                }
            }
        }
        return dist[n - 1]==INT_MAX?-1:dist[n-1];
    }

    vector<vector<pair<int, int>>> createAdj(vector<vector<int>>& edges,
                                             int n) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[2], edge[1]});
            adj[edge[1]].push_back({edge[2] * 2, edge[0]});
        }
        return adj;
    }
};