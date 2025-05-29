class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        const int n = edges1.size() + 1;
        const int m = edges2.size() + 1;

        auto adj1 = createAdj(edges1, n);
        auto adj2 = createAdj(edges2, m);
        auto [even2, _] = levelCheck(adj2);
        auto [even1, isEven] = levelCheck(adj1);

        vector<int> even(n);
        int count = max(even2, m - even2);

        for (int i = 0; i < n; i++)
            even[i] = (isEven[i] ? even1 : n - even1) + count;

        return even;
    }

    pair<int, vector<bool>> levelCheck(vector<vector<int>>& adj) {

        vector<bool> visited(adj.size(), false);
        vector<bool> isEven(adj.size(), false);
        bool flag = true;
        queue<int> q;
        int count = 0;

        q.push(0);
        visited[0] = isEven[0] = true;

        while (!q.empty()) {
            int node = q.front();
            if (isEven[node])
                count++;
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    isEven[neighbor] = !isEven[node];
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return {count, isEven};
    }

    vector<vector<int>> createAdj(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
};