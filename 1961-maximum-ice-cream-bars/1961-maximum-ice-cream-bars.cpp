class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> mp;
        for (int el : costs)
            mp[el]++;

        int idx = 0, res = 0;
        for (auto [el, freq] : mp) {
            while (freq--)
                costs[idx++] = el;
        }

        for (int i = 0; i < costs.size(); i++) {
            coins -= costs[i];
            if (coins < 0)
                return res;
            res++;
        }

        return res;
    }
};