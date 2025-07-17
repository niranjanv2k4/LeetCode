class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,
                      priority_queue<string, vector<string>, greater<string>>>
            adj;
        string start = "JFK";
        vector<string> res;
        unordered_set<string> st;
        
        for (auto ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs(adj, start, res);

        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, priority_queue<string, vector<string>,
                                                  greater<string>>>& adj,
             string& u, vector<string>& res) {

        while (!adj[u].empty()) {
            string neighbor = adj[u].top();
            adj[u].pop();
            dfs(adj, neighbor, res);
        }

        res.push_back(u);
    }
};