class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, result = 0;
        int n = s.size();
        unordered_map<char, int> map;

        for (int i = 0; i < n; i++) {
            map[s[i]]++;
            while (map.size() >= 3) {
                result += n - i;
                if (--map[s[left]] == 0)
                    map.erase(s[left]);
                left++;
            }
        }
        return result;
    }
};