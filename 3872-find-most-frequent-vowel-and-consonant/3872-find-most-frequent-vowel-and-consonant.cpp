class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> fre(26, 0);
        int vowels = 0, consonants = 0;

        for (char ch : s) {
            fre[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (isVowel(i)) {
                vowels = max(vowels, fre[i]);
            } else {
                consonants = max(consonants, fre[i]);
            }
        }

        return vowels + consonants;
    }

private:
    bool isVowel(int i) {
        char ch = i + (int)'a';
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};