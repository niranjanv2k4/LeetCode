class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;

        int n = word.size(), idx;
        int add = n - numFriends + 1;
        string curr = word.substr(0, add);

        for (int i = 1; i < n; i++) {
            string temp = word.substr(i, add);
            if (temp > curr)
                curr = temp;
        }

        return curr;
    }
};