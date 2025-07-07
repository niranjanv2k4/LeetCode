class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int final_day = 0;
        for (auto vec : events) {
            final_day = max(final_day, vec[1]);
        }
        priority_queue<int, vector<int>, greater<>> q;
        int res = 0;
        for (int i = 0, j = 0; i <= final_day; i++) {
            while (j < events.size() && events[j][0] <= i) {
                q.push(events[j][1]);
                j++;
            }
            while (!q.empty() && q.top() < i)
                q.pop();

            if (!q.empty()) {
                q.pop();
                res++;
            }
        }
        return res;
    }
};