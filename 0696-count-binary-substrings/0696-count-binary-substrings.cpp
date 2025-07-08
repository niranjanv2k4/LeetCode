class Solution {
public:
    int countBinarySubstrings(string s) {

        int i = 1, res = 0;
        int prev = 1, curr = 1;
        char first = s[i];

        for(; i<s.size() && s[i]==s[i-1]; i++)
            prev++;
        

        while (i < s.size()) {
            i++;
            for(; i<s.size() && s[i]==s[i-1]; i++) {
                curr++;
            }
            res += min(prev, curr);
            prev = curr;
            curr = 1;
        }

        return res;
    }
};