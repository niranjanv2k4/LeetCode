#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lower_map;
        unordered_map<string, string> vowel_map;

        for (string& s : wordlist) {
            string lower = toLower(s);
            if (!lower_map.count(lower))
                lower_map[lower] = s;
            string vowel = maskVowel(lower);
            if (!vowel_map.count(vowel))
                vowel_map[vowel] = s;
        }

        vector<string> res;
        res.reserve(queries.size());
        for (string& s : queries) {
            if (st.count(s)) {
                res.push_back(s);
                continue;
            }

            string lower = toLower(s);
            if (lower_map.count(lower)) {
                res.push_back(lower_map[lower]);
                continue;
            }

            string vowel = maskVowel(lower);
            if (vowel_map.count(vowel)) {
                res.push_back(vowel_map[vowel]);
                continue;
            }

            res.push_back("");
        }

        return res;
    }

private:
    static string toLower(const string& s) {
        string r;
        r.reserve(s.size());
        for (char c : s)
            r.push_back(tolower(c));
        return r;
    }

    static string maskVowel(const string& s) {
        string res;
        res.reserve(s.size());
        for (char c : s) {
            char lc = tolower(c);
            if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                res.push_back('*');
            else
                res.push_back(lc);
        }
        return res;
    }
};
