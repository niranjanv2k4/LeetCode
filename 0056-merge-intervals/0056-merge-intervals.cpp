class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<int> prev = intervals[0];
        vector<vector<int>> res;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= prev[1]) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                res.push_back(prev);
                prev = intervals[i];
            }
        }

        res.push_back(prev);
        return res;
    }
};