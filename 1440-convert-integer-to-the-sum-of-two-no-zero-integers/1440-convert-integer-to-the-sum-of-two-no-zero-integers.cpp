class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            if (!haveZero(to_string(i)) && !haveZero(to_string(n - i))) {
                return {i, n - i};
            }
        }
        return {-1, -1};
    }

    bool haveZero(string s) {
        for (char c : s) {
            if (c == '0')
                return true;
        }
        return false;
    }
};