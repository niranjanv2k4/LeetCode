class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26);
        unordered_map<char, char> lowest(26);
        for (int i = 0; i < s1.size(); i++) {
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            adj[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        string res = "";
        for (char c : baseStr) {
            if (lowest.find(c) == lowest.end())
                res += bfs(adj, c - 'a', lowest);
            else
                res += lowest[c];
        }
        return res;
    }

    char bfs(vector<vector<int>>& adj, int start,
             unordered_map<char, char>& lowest) {
        vector<bool> visited(adj.size(), false);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        int curr = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            curr = curr < node ? curr : node;
            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return lowest[start] = curr + 'a';
    }
};