class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<long long, int> mp;
        for (int el : costs)
            mp[el]++;

        int res = 0;
        for (auto [el, freq] : mp) {
            if (coins - el * freq < 0)
                return res + coins / el;
            coins -= el * freq;
            res += freq;
        }

        return res;
    }
};