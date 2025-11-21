class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int n = s.size();
        unordered_set<char> st(s.begin(), s.end());
        vector<int> first(26, INT_MAX), last(26, INT_MIN);
        for(int i = 0; i<n; i++){
            first[s[i]-'a'] = min(first[s[i]-'a'], i);
            last[s[i]-'a'] = max(last[s[i]-'a'], i);
        }
        unordered_set<string> palindromes;
        for (char ch : st) {
            for (int k = first[ch - 'a'] + 1; k < last[ch - 'a']; k++) {
                string temp = "";
                temp = temp + ch + s[k] + ch;
                palindromes.insert(temp);
            }
        }
        
        return palindromes.size();
    }
};