class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int res11 = INT_MAX, res12 = INT_MAX;
        for(int i = 0; i<landStartTime.size(); i++){
            res11 = min(res11, landStartTime[i] + landDuration[i]);
        }

        for(int i = 0; i<waterStartTime.size(); i++){
            res12 = min(res12, max(res11, waterStartTime[i]) + waterDuration[i]);
        }

        int res21 = INT_MAX, res22 = INT_MAX;
        for(int i = 0; i<waterStartTime.size(); i++){
            res21 = min(res21, waterStartTime[i] + waterDuration[i]);
        }

        for(int i = 0; i<landStartTime.size(); i++){
            res22 = min(res22, max(res21, landStartTime[i]) + landDuration[i]);
        }

        return min(res12, res22);
    }
};