class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, n = colors.size(), i = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        while (i < n) {
            char curr = colors[i];
            while (i < n && colors[i] == curr) {
                q.push(neededTime[i]);
                i++;
            }
            while (q.size() > 1) {
                res += q.top();
                q.pop();
            }
            while (!q.empty()) {
                q.pop();
            }
        }
        return res;
    }
};