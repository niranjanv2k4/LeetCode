class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        int max_depth = 0;

        for (auto edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        auto dfs = [&](auto&& self, int curr, int parent, int depth) -> void {
            max_depth = max(max_depth, depth);

            for (int neighbor : adj[curr]) {
                if (neighbor != parent) {
                    self(self, neighbor, curr, depth + 1);
                }
            }
        };
        
        dfs(dfs, 0, -1, 0);

        return (int)modPow(2, max_depth - 1);
    }

    long long modPow(long long a, long long b) {
        long long res = 1;
        int MOD = 1e9 + 7;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
};