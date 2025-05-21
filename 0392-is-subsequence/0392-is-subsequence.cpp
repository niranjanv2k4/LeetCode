class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0, tIdx = 0;
        while (tIdx < t.size()) {
            if (sIdx < s.size() && s[sIdx] == t[tIdx])
                sIdx++;
            tIdx++;
        }
        return sIdx == s.size();
    }
};