class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;
        for (string row : bank) {
            int curr = count(row.begin(), row.end(), '1');
            if (curr != 0) {
                res += prev * curr;
                prev = curr;
            }
        }
        return res;
    }
};