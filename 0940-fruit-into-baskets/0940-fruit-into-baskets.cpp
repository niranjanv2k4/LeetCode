class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0, j = 0; i < fruits.size(); i++) {
            map[fruits[i]]++;
            while (j <= i && map.size() > 2) {
                map[fruits[j]]--;
                if (map[fruits[j]] == 0)
                    map.erase(fruits[j]);
                j++;
            }
            if (map.size() <= 2) {
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};