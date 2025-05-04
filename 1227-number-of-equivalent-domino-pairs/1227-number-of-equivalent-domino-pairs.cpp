class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        multiset<vector<int>> set;
        for (const auto& row : dominoes) {
            set.insert(row);
        }
        int result = 0, count = 0;
        for (auto it = set.begin(); it != set.end();) {
            vector<int> e = *it;
            if (e[0] != e[1])
                count = set.count({e[0], e[1]}) + set.count({e[1], e[0]});
            else
                count = set.count(e);
            if (count > 1) {
                result += (count*(count - 1)/2);
            }
            set.erase({e[0], e[1]});
            set.erase({e[1], e[0]});
            it = set.upper_bound(e);
        }
        return result;
    }
};