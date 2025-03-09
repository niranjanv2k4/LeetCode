class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int result = 0, maxlen = 0, curr = 1;

        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int n = colors.size();

        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[i + 1])
                curr++;
            else {
                curr = 1;
                maxlen = 0;
            }
            maxlen = max(maxlen, curr);
            result += maxlen >= k ? 1 : 0;
        }

        return result;
    }
};