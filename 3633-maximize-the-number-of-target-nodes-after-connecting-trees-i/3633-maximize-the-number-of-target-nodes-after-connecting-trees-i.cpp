class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {

        const int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> res(n);

        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int max2 = 0;
        for (int i = 0; i < m; i++)
            max2 = max(max2, atMostK(adj2, i, k - 1));

        for (int i = 0; i < n; i++)
            res[i] = atMostK(adj1, i, k) + max2;

        return res;
    }

    int atMostK(vector<vector<int>>& adj, int start, int k) {

        vector<bool> visited(adj.size(), false);
        queue<int> q;
        int count = 0, length = 0;

        q.push(start);
        visited[start] = true;

        while (!q.empty() && length <= k) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                count++;
                q.pop();
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            length++;
        }
        return count;
    }
};