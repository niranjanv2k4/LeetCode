class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        int m = INT_MAX;
        unordered_map<int, int> freq;
        for (int i = 0; i < basket1.size(); i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            m = min({m, basket1[i], basket2[i]});
        }
        vector<int> merge;
        for (auto [k, c] : freq) {
            if (c % 2 != 0)
                return -1;
            for (int i = 0; i < abs(c) / 2; i++) {
                merge.push_back(k);
            }
        }

        sort(merge.begin(), merge.end());
        long long res = 0;
        for (int i = 0; i < merge.size() / 2; i++) {
            res += min(2 * m, merge[i]);
        }
        return res;
    }
};