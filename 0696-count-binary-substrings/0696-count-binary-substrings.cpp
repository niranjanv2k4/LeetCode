class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int i = 0;
        int c_1 = 0, c_2 = 0;
        char first = s[i];
        while (i < s.size() && s[i] == first) {
            i++;
            c_1++;
        }

        while (i < s.size()) {
            while (i < s.size() && s[i] != first) {
                c_2++;
                i++;
            }
            res += min(c_1, c_2);
            c_1 = c_2;
            c_2=0;
            first = s[i-1];
        }
        return res;
    }
};