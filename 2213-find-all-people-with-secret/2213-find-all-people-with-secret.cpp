class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (vector<int>& vec : meetings) {
            mp[vec[0]].push_back({vec[1], vec[2]});
            mp[vec[1]].push_back({vec[0], vec[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<bool> visited(n, false);

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (auto [nextPerson, t] : mp[person]) {
                if (!visited[nextPerson] && t >= time) {
                    pq.push({t, nextPerson});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};