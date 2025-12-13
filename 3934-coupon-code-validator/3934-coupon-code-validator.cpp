class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<vector<string>> temp;
        for (int i = 0; i < code.size(); i++) {
            bool flag = true;
            for (char ch : code[i]) {
                if (!isalnum(ch) && ch != '_') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if ((businessLine[i] == "electronics" ||
                     businessLine[i] == "grocery" ||
                     businessLine[i] == "pharmacy" ||
                     businessLine[i] == "restaurant") &&
                    isActive[i] && code[i][0] != '\0') {
                    temp.push_back({businessLine[i], code[i]});
                }
            }
        }
        sort(temp.begin(), temp.end());
        vector<string> res;
        for (auto el : temp)
            res.push_back(el[1]);
        return res;
    }
};