class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> last;
        set<int> dry;

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dry.insert(i);
            } else {
                int lake = rains[i];
                res[i] = -1;

                if (last.count(lake)) {

                    auto it = dry.lower_bound(last[lake]);
                    if (it == dry.end())
                        return {};
                    res[*it] = lake;
                    dry.erase(it);
                }
                last[lake] = i;
            }
        }
        return res;
    }
};