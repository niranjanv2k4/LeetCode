class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        vector<bool> flags(26, true);
        int res = 0;

        for (char ch : word)
            mp[ch]++;

        for (char ch : word) {
            if (isupper(ch) && mp.find(tolower(ch)) != mp.end() &&
                flags[tolower(ch) - 'a']) {
                if (mp[tolower(ch)] == 0)
                    res++;
                flags[tolower(ch) - 'a'] = false;
            }

            if (islower(ch))
                mp[ch]--;
        }

        return res;
    }
};