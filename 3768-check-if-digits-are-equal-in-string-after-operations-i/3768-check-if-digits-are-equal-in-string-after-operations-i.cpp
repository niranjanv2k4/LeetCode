class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() != 2) {
            string temp = "";
            for (int i = 0; i + 1 < s.size(); i++) {
                int num = s[i] - '0' + s[i + 1] - '0';
                temp += (num % 10) + '0';
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};