class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (int el : nums)
            mp[el]++;

        int res = 1;

        if (mp.find(1) != mp.end()) {
            res = mp[1] - (mp[1] % 2 == 0);
            mp.erase(1);
        }

        for (auto it = mp.begin(); it != mp.end();) {

            long long el = it->first;

            if (mp[el] > 1 && el != 1) {
                int curr = 1;
                el *= el;
                while (mp.find(el) != mp.end()) {
                    curr += 2;
                    if (mp[el] == 1)
                        break;
                    mp.erase(el);
                    el *= el;
                }
                res = max(res, curr);
            }
            it++;
        }

        return res;
    }
};