class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> mp;
        return solve(0, s, k, 0, false, mp);
    }

    int solve(long long mask, string& s, int k, int idx, bool changed,
              unordered_map<long long, int>& mp) {
        if (idx == s.size())
            return 1;

        long long key = ((long long)idx << 32) | (mask << 1) | (changed);
        if (mp.find(key) != mp.end())
            return mp[key];

        int res = 0;
        long long val = 1 << (s[idx] - 'a');
        int count = __builtin_popcount(mask | val);

        if (count > k) {
            res = max(res, 1 + solve(val, s, k, idx + 1, changed, mp));
        } else {
            res = max(res, solve(mask | val, s, k, idx + 1, changed, mp));
        }

        if (changed)
            return mp[key] = res;

        for (int ch = 0; ch < 26; ch++) {
            long long new_mask = mask | (1 << ch);
            if (__builtin_popcount(new_mask) > k) {
                res = max(res, 1 + solve(1 << ch, s, k, idx + 1, true, mp));
            } else {
                res = max(res, solve(new_mask, s, k, idx + 1, true, mp));
            }
        }
        return mp[key] = res;
    }
};