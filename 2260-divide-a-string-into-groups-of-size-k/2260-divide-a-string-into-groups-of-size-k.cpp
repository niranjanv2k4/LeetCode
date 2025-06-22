class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for (int i = 0; i < s.size(); i += k) {
            res.push_back(s.substr(i, k));
        }
        res.back() += string(k - res.back().size(), fill);
        return res;
    }
};