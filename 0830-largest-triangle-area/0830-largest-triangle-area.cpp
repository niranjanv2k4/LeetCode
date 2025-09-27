class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0;
        for (int i = 0; i < points.size() - 2; i++) {
            for (int j = i + 1; j < points.size() - 1; j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    max_area =
                        max(max_area, area(points[i], points[j], points[k]));
                }
            }
        }
        return max_area;
    }

    double area(vector<int>& x, vector<int>& y, vector<int>& z) {
        double res = 0;
        res = abs(x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) +
                  z[0] * (x[1] - y[1]));
        return res * 0.5;
    }
};