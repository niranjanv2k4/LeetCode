class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<bool>> isReachable(n, vector<bool>(n, false));
        vector<bool> res(queries.size(), false), visited(n, false);
        vector<vector<int>> adj(n);
        queue<int> q;

        if (prerequisites.size() == 0)
            return res;

        for (auto& prerequisite : prerequisites) 
            adj[prerequisite[0]].push_back(prerequisite[1]);

        for (int i = 0; i < n; i++) {
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                isReachable[i][node] = true;
                for (int v : adj[node]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            fill(visited.begin(), visited.end(), false);
        }
    
        for (int i = 0; i < queries.size(); i++) {
            if (isReachable[queries[i][0]][queries[i][1]])
                res[i] = true;
        }
        return res;
    }
};