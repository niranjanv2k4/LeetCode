class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> res;
        res.push_back(words[0]);
        bool flag = groups[0];;
        for (int i = 1; i < groups.size(); i++) {
            if (groups[i]!=flag){
                res.push_back(words[i]);
                flag = groups[i];
            }
        }
        return res;
    }
};