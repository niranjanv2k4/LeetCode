class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        unordered_map<int, int> max_val, min_val;
        for (int i = 0; i < rating.size(); i++) {
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] < rating[i])
                    max_val[i]++;
                else
                    min_val[i]++;
            }
        }
        for (int i = 0; i < rating.size(); i++) {
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[i] > rating[j]){
                    res += max_val[j];
                }
                else{
                    res += min_val[j];
                }
            }
        }
        return res;
    }
};