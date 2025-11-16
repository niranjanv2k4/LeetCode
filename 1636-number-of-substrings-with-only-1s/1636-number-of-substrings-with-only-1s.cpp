class Solution {
public:
    int numSub(string s) {
        long long curr = 0, count = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < s.size(); i++) {
            while (s[i] == '1' && i < s.size()) {
                count++;
                i++;
            }
            curr = (curr + (count * (count + 1)) / 2) % MOD;
            count = 0;
        }

        int res = curr%MOD;
        return res;
    }
};