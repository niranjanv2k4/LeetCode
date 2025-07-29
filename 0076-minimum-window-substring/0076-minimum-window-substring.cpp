class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size())
            return "";

        vector<int> fre1(128, 0), fre2(128, 0);

        for (char& ch : t) 
            fre1[ch]++;
        

        int j = 0;
        string res;
        for (int i = 0; i < s.size(); i++) {
            fre2[s[i]]++;
            if (isValid(fre1, fre2)) {
                while (j <= i) {
                    if (fre1[s[j]] > 0 && fre2[s[j]] - 1 < fre1[s[j]])
                        break;
                    fre2[s[j]]--;
                    j++;
                }
                if (res.size() == 0)
                    res = s.substr(j, i - j + 1);
                else if (i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        
        return res;
    }

    bool isValid(vector<int>& fre1, vector<int>& fre2) {
        for (int i = 0; i < 128; i++) {
            if (fre1[i] > 0 && fre2[i] < fre1[i])
                return false;
        }
        return true;
    }
};