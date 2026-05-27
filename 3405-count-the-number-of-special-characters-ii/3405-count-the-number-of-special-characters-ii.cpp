class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        int res = 0;

        for (char ch : word)
            mp[ch]++;

        for (char ch : word) {
            char lower_ch = tolower(ch);
            
            if (isupper(ch) && mp.find(lower_ch) != mp.end()) {
                if (mp[lower_ch] == 0)
                    res++;
                mp.erase(lower_ch);
            }

            if (islower(ch))
                mp[ch]--;
        }

        return res;
    }
};