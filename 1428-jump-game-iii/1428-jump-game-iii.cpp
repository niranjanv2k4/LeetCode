class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        queue<int> q;
        vector<bool> vis(arr.size(), false);

        q.push(start);

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            if (arr[curr] == 0)
                return true;

            vis[curr] = true;

            if (curr + arr[curr] >= 0 && curr + arr[curr] < arr.size() &&
                !vis[curr + arr[curr]])
                q.push(curr + arr[curr]);
                
            if (curr - arr[curr] >= 0 && curr - arr[curr] < arr.size() &&
                !vis[curr - arr[curr]])
                q.push(curr - arr[curr]);
        }

        return false;
    }
};