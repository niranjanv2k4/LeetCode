class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        for(int i = 0; i<landStartTime.size(); i++){
            for(int j = 0; j < waterStartTime.size(); j++){
                    res = min(res, max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j]);
                    res = min(res, max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i]);
                
            }
        }

        return res;
    }
};