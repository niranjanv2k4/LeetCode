class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;

        int n = word.size();
        int add = n - numFriends + 1;
        string curr = word.substr(0, add);
        string temp = curr;

        for (int i = 1; i < n; i++) {
            if (i + add - 1 < n)
                temp += word[i + add - 1];
            if (temp.substr(i, add) > curr)
                curr = temp.substr(i, add);
        }
        
        return curr;
    }
};