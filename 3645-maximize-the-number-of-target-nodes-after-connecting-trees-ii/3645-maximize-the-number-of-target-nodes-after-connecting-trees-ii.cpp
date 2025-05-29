class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        const int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> even(n);

        auto adj1 = createAdj(edges1, n);
        auto adj2 = createAdj(edges2, m);
        auto isEven = levelCheck(adj1);

        int even2 = totalVertex2(adj2);
        int count = max(even2, m - even2);
        int even1 = totalVertex2(adj1);

        for (int i = 0; i < n; i++) {
            if (isEven[i])
                even[i] = even1 + count;
            else
                even[i] = n - even1 + count;
        }
        return even;
    }

    int totalVertex2(vector<vector<int>>& adj) {

        vector<bool> visited(adj.size(), false);
        queue<int> q;
        int count = 0;
        bool flag = true;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                if (flag)
                    count++;
                q.pop();
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            flag = !flag;
        }
        return count;
    }
    vector<bool> levelCheck(vector<vector<int>>& adj) {

        vector<bool> visited(adj.size(), false);
        vector<bool> isEven(adj.size(), false);
        queue<int> q;
        bool flag = true;

        q.push(0);
        visited[0] = true;
        isEven[0] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                if (flag)
                    isEven[node] = true;
                q.pop();
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            flag = !flag;
        }
        return isEven;
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