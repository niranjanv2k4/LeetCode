class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        queue<int> q;
        vector<bool> visited(n, false), isAdded(n, false);
        int res = 0;

        for (int box : initialBoxes) {
            isAdded[box]=true;
            if (status[box] == 1){
                q.push(box);
                visited[box]=true;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res += candies[node];
            for (int key : keys[node]) {
                status[key] = 1;
                if (!visited[key] && isAdded[key]){
                    visited[key] = true;
                    q.push(key);
                }
            }
            for (int box : containedBoxes[node]) {
                if (status[box] == 1 && !visited[box]) {
                    visited[box] = true;
                    q.push(box);
                }
                isAdded[box] = true;
            }
        }

        return res;
    }
};