class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            inDegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        int processed = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;
            for (int v : adj[node]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
        return processed == numCourses;
    }
};