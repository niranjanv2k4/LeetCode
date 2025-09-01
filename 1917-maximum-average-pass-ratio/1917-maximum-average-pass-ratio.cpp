class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            double first = (float)classes[i][0] / classes[i][1];
            double last = ((float)classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push({last - first, i});
        }

        while (extraStudents--) {
            auto [change, index] = pq.top();
            pq.pop();
            classes[index][0]++;
            classes[index][1]++;
            double first = (float)classes[index][0] / classes[index][1];
            double last =
                ((float)classes[index][0] + 1) / (classes[index][1] + 1);
            pq.push({last - first, index});
        }

        double res = 0;

        for (auto vec : classes) {
            res += (float)vec[0] / vec[1];
        }

        return res / classes.size();
    }
};