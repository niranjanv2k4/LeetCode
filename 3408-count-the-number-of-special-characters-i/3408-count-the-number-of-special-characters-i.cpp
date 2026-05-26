class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st(word.begin(), word.end());
        int res = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(st.find(ch) != st.end() && st.find(toupper(ch)) != st.end())
                res++;
        }

        return res;
    }
};