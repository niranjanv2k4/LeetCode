class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        int i = 0, idx = 0;
        
        vector<int> parent(n), rank(n, 0), res;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {

            int from = edge[0]-1, to = edge[1]-1;
            int p_from = find(parent, from);
            int p_to = find(parent, to);
            
            if (p_from != p_to) {
                union_find(p_from, p_to, rank, parent);
            } else {
                res = {from+1, to+1};
            }

        }

        return res;
    }

    int find(vector<int>& parent, int u) {
        if (u != parent[u])
            parent[u] = find(parent, parent[u]);
        return parent[u];
    }

    void union_find(int p_from, int p_to, vector<int>& rank, vector<int>& parent){
        if(rank[p_from]<rank[p_to]){
            parent[p_from] = p_to;
        }else if(rank[p_from]>rank[p_to]){
            parent[p_to] = p_from;
        }else{
            parent[p_from] = p_to;
            rank[p_from]++;
        }
    }
};