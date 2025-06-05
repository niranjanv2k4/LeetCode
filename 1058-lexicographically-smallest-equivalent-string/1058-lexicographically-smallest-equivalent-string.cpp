class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> groups(26, -1);
        for (int i = 0; i < s1.size(); i++) {
            int one = find(groups, s1[i] - 'a');
            int two = find(groups, s2[i] - 'a');
            if (one != two) {
                if (two < one) {
                    groups[one] = two;
                } else
                    groups[two] = one;
            }
        }
        string res = "";
        for (char c : baseStr)
            res += find(groups, c - 'a') + 'a';
        return res;
    }

    int find(vector<int>& groups, int c) {
        if (groups[c] == -1)
            return c;
        return groups[c] = find(groups, groups[c]);
    }
};