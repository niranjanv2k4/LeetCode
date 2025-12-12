class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {

        sort(events.begin(), events.end(),
             [&](const vector<string>& a, const vector<string>& b) {
                 int at = stoi(a[1]);
                 int bt = stoi(b[1]);
                 if (at != bt) {
                     return at < bt;
                 }
                 if (b[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });

        vector<int> res(numberOfUsers, 0), status(numberOfUsers, 0);

        for (auto& event : events) {
            string type = event[0];
            int curr = stoi(event[1]);
            string users = event[2];

            if (type == "OFFLINE") {
                status[extractVal(users)] = curr + 60;
            } else {

                if (users == "ALL") {
                    for (int id = 0; id < numberOfUsers; id++) {
                        res[id]++;
                    }

                } else if (users == "HERE") {
                    for (int id = 0; id < numberOfUsers; id++) {
                        if (status[id] <= curr) {
                            res[id]++;
                        }
                    }

                } else {
                    stringstream ss(users);
                    string user;

                    while (ss >> user) {
                        res[extractVal(user)]++;
                    }
                }
            }
        }

        return res;
    }

    int extractVal(const string& s) {
        int id = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                id = id * 10 + (s[i] - '0');
            }
        }
        return id;
    }
};