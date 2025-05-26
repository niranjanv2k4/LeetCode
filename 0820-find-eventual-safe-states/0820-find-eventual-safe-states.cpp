class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<vector<int>> temp(n);
        vector<int> outDegree(n, 0), res;
        queue<int> q;

        for(int i = 0; i<n; i++){
            outDegree[i]=graph[i].size();
            for(int v:graph[i]){
                temp[v].push_back(i);
            }
            if (outDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int v : temp[node]) {
                if (--outDegree[v] == 0)
                    q.push(v);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};