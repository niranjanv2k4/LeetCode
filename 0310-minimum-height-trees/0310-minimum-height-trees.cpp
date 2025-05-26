class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0), res;
        queue<int> q;
        int remaining = n, size, node;

        for (auto edge : edges) {
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                q.push(i);
            }
        }
        while (remaining > 2) {
            size = q.size();
            remaining -= size;
            while (size--) {
                node = q.front();
                q.pop();
                for (int v : adj[node])
                    if (--inDegree[v] == 1)
                        q.push(v);
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};