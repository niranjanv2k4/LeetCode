class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dp(n, 0), dist(n, LLONG_MAX);
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& edge : roads) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        dist[0] = 0;
        dp[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                    dp[v] = dp[u] % MOD;
                } else if (dist[u] + w == dist[v]) {
                    dp[v] = (dp[v] + dp[u]) % MOD;
                }
            }
        }
        for (int c : dist)
            cout << c << " ";
        return dp[n - 1];
    }
};