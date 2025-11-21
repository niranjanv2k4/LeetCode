class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int n = s.size();
        unordered_set<char> st(s.begin(), s.end());
        unordered_set<string> palindromes;
        for (char ch : st) {
            int i = 0, j = n - 1;
            for (; i < s.size(); i++) {
                if (s[i] == ch)
                    break;
            }

            for (; j > i; j--) {
                if (s[j] == ch)
                    break;
            }
            for (int k = i + 1; k < j; k++) {
                string temp = "";
                temp = temp + ch + s[k] + ch;
                palindromes.insert(temp);
            }
        }
        
        return palindromes.size();
    }
};