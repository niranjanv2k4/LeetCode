class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        auto get_sum = [&](string s) {
            int res = 0;
            for (char ch : s) {
                res += weights[ch - 'a'];
            }
            return res % 26;
        };

        string res = "";
        for (string s : words) 
            res += (25 - get_sum(s) + 'a');
        

        return res;
    }
};