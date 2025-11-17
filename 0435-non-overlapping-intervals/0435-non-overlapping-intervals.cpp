class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        int prev = INT_MIN;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[1] == b[1])return a[0]<b[0];
            return a[1] < b[1];
        });
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i][0] < prev){
                res++;
            }else{
                prev = intervals[i][1];
            }
        }
        return res;
    }
};