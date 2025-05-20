class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string max_str = s.substr(0, 1);
        auto expand = [&s](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(i, i);
            string even = expand(i, i + 1);

            if (odd.size() > max_str.size())
                max_str = odd;
            if (even.size() > max_str.size())
                max_str = even;
        }
        return max_str;
    }
};