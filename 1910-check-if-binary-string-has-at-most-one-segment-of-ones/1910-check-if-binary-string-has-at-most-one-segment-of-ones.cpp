class Solution {
public:
    bool checkOnesSegment(string s) {

        int i = 0;
        while (i < s.size() && s[i] == '1')
            i++;

        if (i == s.size())
            return true;

        while (i < s.size() && s[i] == '0')
            i++;

        return i == s.size();
    }
};