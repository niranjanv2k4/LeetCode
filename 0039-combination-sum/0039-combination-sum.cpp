class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> curr;
        recurse(st,  candidates, target, 0, curr);

        return vector<vector<int>>(st.begin(), st.end());
    }

    void recurse(set<vector<int>>& st, vector<int>& candidates, int target, int idx, vector<int>& curr){
        if(target == 0){
            st.insert(curr);
            return;
        }
        if(target < 0 || idx ==candidates.size())
            return;

        recurse(st, candidates, target, idx + 1, curr);

        curr.push_back(candidates[idx]);
        recurse(st, candidates, target - candidates[idx], idx, curr);
        curr.pop_back();

        return;
    }
};