class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;

        for (auto pattern : patterns)
            res += is_substring(pattern, word);

        return res;
    }

    bool is_substring(string s, string word) {
        for (int i = 0; i < (int)(word.size() - s.size()) + 1; i++) {
            int j = 0;
            while (j < s.size()) {
                if (s[j] != word[i + j])
                    break;
                j++;
            }
            if (j == s.size())
                return true;
        }

        return false;
    }
};