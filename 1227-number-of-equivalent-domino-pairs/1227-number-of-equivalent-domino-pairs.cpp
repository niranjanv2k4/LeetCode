class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        int result = 0;
        for(const auto &el: dominoes){
            int num = (el[0]>el[1]?el[0]:el[1])*10+(el[0]>el[1]?el[1]:el[0]);
            map[num]++;
            if(map[num]>1){
                result+=(map[num]-1);
            }
        }
        return result;
    }
};