class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> f(n, 0);

        for (int i = 0; i < m; i++) {
            long long now = f[0];
            for (int j = 1; j < n; j++) {
                now = max(f[j], now + skill[j - 1] * mana[i]);
            }
            f[n - 1] = now + skill[n - 1] * mana[i];
            for (int j = n - 2; j >= 0; j--) {
                f[j] = f[j + 1] - skill[j + 1] * mana[i];
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};