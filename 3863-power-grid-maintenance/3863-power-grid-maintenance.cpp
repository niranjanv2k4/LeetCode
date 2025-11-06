class Solution {
public:
    vector<int> parent, rank;
    map<int, set<int>> mp;

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c);
        rank.resize(c, 0);
        for (int i = 0; i < c; i++) parent[i] = i;

        for (auto& connection : connections) {
            int u = connection[0] - 1, v = connection[1] - 1;
            unity(u, v);
        }

        for (int i = 0; i < c; i++) {
            mp[findPar(i)].insert(i + 1);
        }

        vector<bool> online(c, true);
        vector<int> res;

        for (auto& query : queries) {
            int type = query[0];
            int node = query[1] - 1;
            int p = findPar(node);

            if (type == 1) {
                if (online[node]) {
                    res.push_back(node + 1);
                } else {
                    if (mp[p].empty()) res.push_back(-1);
                    else res.push_back(*mp[p].begin());
                }
            } else { 
                if (online[node]) {
                    online[node] = false;
                    mp[p].erase(node + 1);
                }
            }
        }

        return res;
    }

    int findPar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findPar(parent[x]);
    }

    void unity(int u, int v) {
        int p_u = findPar(u);
        int p_v = findPar(v);
        if (p_u == p_v) return;
        if (rank[p_u] < rank[p_v]) swap(p_u, p_v);
        parent[p_v] = p_u;
        if (rank[p_u] == rank[p_v]) rank[p_u]++;
    }
};
