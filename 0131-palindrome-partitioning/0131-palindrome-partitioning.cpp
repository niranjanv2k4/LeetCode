class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        recurse(res, temp, 0, s);
        return res;
    }

    void recurse(vector<vector<string>>& res, vector<string>& temp, int idx,
                 string& s) {
        if (idx == s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                recurse(res, temp, i + 1, s);
                temp.pop_back();
            }
        }
    }

    bool isPal(string& s, int l, int r) {

        while (l < r)
            if (s[l++] != s[r--])
                return false;

        return true;
    }
};