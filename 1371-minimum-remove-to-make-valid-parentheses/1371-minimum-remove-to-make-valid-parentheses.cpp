class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "", res = "";
        int count = 0;
        for (int c : s) {
            count += (c == '(');
            if (c == ')') {
                if (count > 0) {
                    count--;
                } else
                    continue;
            }
            temp += c;
        }
        count = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            count += (temp[i] == ')');
            if (temp[i] == '(') {
                if (count > 0) {
                    count--;
                } else
                    continue;
            }
            res += temp[i];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};