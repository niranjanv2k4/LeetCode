class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        const int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i = 0; i<n; i++){
            dp[i][colors[i]-'a'] = 1;
        }
        return topologicalSort(colors, edges, dp, n);
    }

    int topologicalSort(const string colors, vector<vector<int>>& edges, vector<vector<int>>& dp, int n) {
        vector<int> inDegree(n, 0);
        int processed = 0;
        vector<vector<int>> adj(n);
        queue<int> q;
        int res = 1;
        for (auto& edge : edges){
            inDegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;
            for (int v : adj[node]){
                for(int i = 0; i<26; i++){
                    dp[v][i]=max(dp[v][i], dp[node][i]+((colors[v]-'a'==i)?1:0));
                    res=max(res, dp[v][i]);
                }
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
       return processed!=n?-1:res;
    }
};