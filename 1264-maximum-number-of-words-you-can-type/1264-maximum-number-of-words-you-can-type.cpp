class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        stringstream ss(text);
        string temp;
        int res = 0;

        while (ss >> temp) {
            bool flag = true;
            for (char c : temp) {
                if (brokenLetters.find(c) != string::npos) {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }

        return res;
    }
};