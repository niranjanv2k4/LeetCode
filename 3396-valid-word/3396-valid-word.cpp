class Solution {
public:
    bool isValid(string word) {

        if (word.size() < 3)
            return false;

        bool vowel = false, consonant = false;

        for (int i = 0; i < word.size(); i++) {
            if (!isalnum(word[i]))
                return false;
                
            if (isdigit(word[i]))
                continue;
            else if (isVowel(word[i])) 
                vowel = true;
            else
                consonant = true;
        }

        return vowel && consonant;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};