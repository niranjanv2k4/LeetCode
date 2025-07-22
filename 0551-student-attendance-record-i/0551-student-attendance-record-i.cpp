class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A')
                absent++;
            if (absent > 1)
                return false;
            if (i > 1) {
                if (s[i] == s[i - 1] && s[i - 2] == s[i - 1] && s[i] == 'L')
                    return false;
            }
        }
        
        return true;
    }
};