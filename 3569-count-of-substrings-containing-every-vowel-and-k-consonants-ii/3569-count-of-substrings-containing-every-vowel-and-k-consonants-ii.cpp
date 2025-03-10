class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atleastK(word, k) - atleastK(word, k + 1);
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atleastK(string word, int k) {
        int con = 0, right = 0, left = 0;
        int n = word.size();
        long long result = 0;
        unordered_map<char, int> vow;

        for (int right = 0; right < n; right++) {
            if (isVowel(word[right])) {
                vow[word[right]]++;
            } else {
                con++;
            }

            while (vow.size() == 5 && con >= k) {
                result += n - right;
                if (isVowel(word[left])) {
                    vow[word[left]]--;
                    if (vow[word[left]] == 0) {
                        vow.erase(word[left]);
                    }
                } else {
                    con--;
                }
                left++;
            }
        }
        
        return result;
    }
};