class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        const int n = edges.size();
        int res = -1, minVal = INT_MAX;

        auto dist1 = dfs(node1, edges);
        auto dist2 = dfs(node2, edges);
        
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

    vector<int> dfs(int vertex, vector<int>& edges) {
        vector<int> dist(edges.size(), -1);
        int len = 0;

        while (vertex != -1 && dist[vertex] == -1) {
            dist[vertex] = len++;
            vertex = edges[vertex];
        }
        
        return dist;
    }
};