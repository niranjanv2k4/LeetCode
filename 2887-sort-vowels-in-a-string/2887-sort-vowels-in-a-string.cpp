class Solution {
public:
    string sortVowels(string s) {

        string temp = "", res = "";
        int i = 0;

        for (char c : s) {
            if (isVowel(tolower(c))) {
                temp += c;
            }
        }

        sort(temp.begin(), temp.end());

        for (char c : s) 
            res += isVowel(tolower(c)) ? temp[i++] : c;
        
        return res;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};