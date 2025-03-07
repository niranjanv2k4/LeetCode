class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int i = word1.size() < word2.size() ? word1.size() : word2.size(),
            j = 0;
        string result;

        while (j < i) {
            result = result + word1[j] + word2[j];
            j++;
        }

        if (word1.size() > word2.size()) {
            return result + word1.substr(j, word1.size() - j);
        }

        return result + word2.substr(j, word2.size() - j);
    }
};