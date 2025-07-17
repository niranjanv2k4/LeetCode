class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k - 1});
        dist[k - 1] = 0;
        auto adj = createAdj(times, n);
        while (!pq.empty()) {
            auto [total, node] = pq.top();
            pq.pop();
            if (total > dist[node])
                continue;
            for (auto [weight, next] : adj[node]) {
                if (dist[next] > dist[node] + weight) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        int res = INT_MIN;
        for (int c : dist) {
            if (c == INT_MAX)
                return -1;
            else
                res = max(res, c);
        }
        return res;
    }

    vector<vector<pair<int, int>>> createAdj(vector<vector<int>>& edges,
                                             int n) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0] - 1].push_back({edge[2], edge[1] - 1});
        }
        return adj;
    }
};