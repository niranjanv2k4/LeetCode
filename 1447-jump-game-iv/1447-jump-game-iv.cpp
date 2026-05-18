class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        vector<bool> vis(arr.size(), false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        int steps = 0;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == arr.size() - 1)
                    return steps;


                if (curr + 1 < arr.size() && !vis[curr + 1]){
                    q.push(curr + 1);
                    vis[curr + 1] = true;
                }

                if (curr - 1>= 0 && !vis[curr - 1]){
                    q.push(curr - 1);
                    vis[curr - 1] = true;
                }

                for (int idx : mp[arr[curr]]) {
                    if (!vis[idx]) {
                        q.push(idx);
                        vis[idx] = true;
                    }
                }
                mp[arr[curr]].clear();
            }

            steps++;
        }

        return -1;
    }
};