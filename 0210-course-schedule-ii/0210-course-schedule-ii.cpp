class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0), res;
        queue<int> q;

        for (auto& el : prerequisites) {
            inDegree[el[0]]++;
            adj[el[1]].push_back(el[0]);
        }

        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int v : adj[node]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
        if (res.size() != numCourses)
            return {};
        return res;
    }
};