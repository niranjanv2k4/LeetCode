class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> hash(256, 0);

        for (const char& ch : t) {
            hash[ch]++;
        }

        int l = 0, r = 0, count = 0, minLen = 1e6, startIndex = -1;

        while (r < n) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            while (count == m) {
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};