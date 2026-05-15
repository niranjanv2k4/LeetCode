class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> freq;
        int res = 0;
        for (int start = 0, end = 0; end < s.size(); end++) {
            freq[s[end] ]++;
            if (freq[s[end] ] == 2) {
                while (start <= end && freq[s[end]] != 1) {
                    freq[s[start] ]--;
                    start++;
                }
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};