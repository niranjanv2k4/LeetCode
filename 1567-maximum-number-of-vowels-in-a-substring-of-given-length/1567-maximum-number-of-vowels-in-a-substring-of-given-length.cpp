class Solution {
public:
    int maxVowels(string s, int k) {
        if (k > s.size())
            return 0;

        int result = INT_MIN, curr = 0;
        int i = 0, j = 0;

        for (i; i < k; i++) {
            if (isVowel(s[i]))
                curr++;
        }

        result = max(result, curr);
        while (i < s.size()) {
            if (isVowel(s[i++]))
                curr++;
            if (isVowel(s[j++]))
                curr--;
            result = max(result, curr);
        }

        return result;
    }
    
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};