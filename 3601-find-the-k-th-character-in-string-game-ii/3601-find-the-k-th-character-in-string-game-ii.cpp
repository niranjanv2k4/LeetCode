class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        int idx = 0;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t] == 1)
                ans++;
        }
        return 'a' + ans%26;
    }
};