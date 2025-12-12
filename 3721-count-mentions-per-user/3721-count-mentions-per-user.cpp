class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {

        stable_sort(events.begin(), events.end(),
                    [](const vector<string>& a, const vector<string>& b) {
                        int ta = stoi(a[1]);
                        int tb = stoi(b[1]);

                        if (ta != tb)
                            return ta < tb;

                        bool aOff = (a[0] == "OFFLINE");
                        bool bOff = (b[0] == "OFFLINE");

                        return aOff && !bOff;
                    });

        vector<int> res(numberOfUsers, 0);
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        int n = events.size();
        int i = 0;

        for (int time = stoi(events[0][1]);
             i < n && time <= stoi(events[n - 1][1]); time++) {

            vector<int> del;
            for (auto& p : mp) {
                auto& pq = p.second;
                while (!pq.empty() && pq.top() <= time)
                    pq.pop();
                if (pq.empty())
                    del.push_back(p.first);
            }
            for (int id : del)
                mp.erase(id);

            while (i < n && stoi(events[i][1]) == time) {

                stringstream ss(events[i][2]);
                string user;

                if (events[i][0] == "OFFLINE") {

                    while (ss >> user) {
                        int id = extractVal(user);
                        mp[id].push(time + 60);
                    }

                } else if (events[i][2] == "ALL") {

                    for (int id = 0; id < numberOfUsers; id++)
                        res[id]++;

                } else if (events[i][2] == "HERE") {

                    for (int id = 0; id < numberOfUsers; id++)
                        if (mp.find(id) == mp.end())
                            res[id]++;

                } else {

                    while (ss >> user) {
                        int id = extractVal(user);
                        // if (mp.find(id) == mp.end())
                            res[id]++;
                    }
                }

                i++;
            }
        }

        return res;
    }

    int extractVal(string s) {
        int id = 0;
        for (char c : s)
            if (isdigit(c))
                id = id * 10 + (c - '0');
        return id;
    }
};
