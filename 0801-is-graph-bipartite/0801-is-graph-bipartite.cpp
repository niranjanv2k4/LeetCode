class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (visited[i] != 0)
                continue;

            visited[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (visited[neighbor] == 0) {
                        visited[neighbor] = -visited[node];
                        q.push(neighbor);
                    } else {
                        if (visited[neighbor] == visited[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};