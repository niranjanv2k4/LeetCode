class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, pair<int, int>> mp1, mp2;

        for (auto& el : buildings) {
            int r = el[0];
            int c = el[1];

            if (mp1.find(r) != mp1.end()) {
                mp1[r].first = min(mp1[r].first, c);
                mp1[r].second = max(mp1[r].second, c);
            } else {
                mp1[r].first = mp1[r].second = c;
            }

            if (mp2.find(c) != mp2.end()) {
                mp2[c].first = min(mp2[c].first, r);
                mp2[c].second = max(mp2[c].second, r);
            } else {
                mp2[c].first = mp2[c].second = r;
            }
        }

        int res = 0;
        for (auto& el : buildings) {
            int r = el[0];
            int c = el[1];
            if (c > mp1[r].first && c < mp1[r].second && r > mp2[c].first &&
                r < mp2[c].second) {
                res++;
            }
        }
        return res;
    }
};