class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s){
            freq[c - 'a']++;
        }
        int diff_1 = 0, diff_2 = INT_MAX;
        for (int c : freq) {
            if (c == 0)
                continue;
            if (c % 2 == 0 && c < diff_2)
                diff_2 = c;
            if (c % 2 == 1 && c > diff_1)
                diff_1 = c;
        }
        return diff_1 - diff_2;
    }
};