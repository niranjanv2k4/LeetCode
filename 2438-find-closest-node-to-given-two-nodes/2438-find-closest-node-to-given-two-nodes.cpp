class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(dist1, 0, node1, edges);
        dfs(dist2, 0, node2, edges);
        int res = -1, minVal = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                if (minVal >= max(dist1[i], dist2[i])) {
                    res = i;
                    minVal = max(dist1[i], dist2[i]);
                }
            }
        }
        return res;
    }

    void dfs(vector<int>& dist, int k, int vertex, vector<int>& edges) {
        dist[vertex] = k;
        if (edges[vertex] != -1 && dist[edges[vertex]] == -1)
            dfs(dist, k + 1, edges[vertex], edges);
    }
};