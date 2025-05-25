class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map, same;
        for (string word : words) 
            map[word]++;
        
        int res = 0;
        bool flag = false;
        for (auto& [key, value] : map) {
            string rev = key;
            reverse(rev.begin(), rev.end());
            if (map.count(rev)) {
                if (rev != key) {
                    res += 4 * min(map[rev], map[key]);
                } else {
                    res += 4 * (value / 2);
                    if (value % 2 == 1)
                        flag = true;
                }
                map[rev] = 0;
            }
            map[key] = 0;
        }

        return flag ? res + 2 : res;
    }
};