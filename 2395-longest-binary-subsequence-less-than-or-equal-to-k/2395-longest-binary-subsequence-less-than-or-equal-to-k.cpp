class Solution {
public:
    unordered_map<int, int> map;
    int longestSubsequence(string s, int k) {

        int res = count(s.begin(), s.end(), '0');
        int n = s.size();

        long long curr = 1;
        long long num = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                num += curr;
                if (num <= k)
                    res++;
            }
            if (num > k || curr > k)
                break;
            curr *= 2;
        }

        return res;
    }
};