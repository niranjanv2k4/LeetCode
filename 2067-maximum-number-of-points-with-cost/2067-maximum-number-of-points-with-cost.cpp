class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int n = points.size(), m = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end());

        for (int row = 1; row < n; row++) {

            vector<long long> left(m), right(m), curr(m);

            left[0] = prev[0];
            for (int i = 1; i < m; i++) 
                left[i] = max(left[i - 1], prev[i] + i);
            
            right[m - 1] = prev[m - 1] - (m - 1);
            for (int i = m - 2; i >= 0; i--) 
                right[i] = max(right[i + 1], prev[i] - i);
            

            for (int i = 0; i < m; i++) 
                curr[i] = max(left[i] - i, right[i] + i) + points[row][i];
            
            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};