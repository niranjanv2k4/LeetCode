class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (j == i || !(x1 <= x2 && y1 >= y2))
                    continue;
                bool flag = false;
                for (int k = 0; k < points.size(); k++) {
                    if (i == k || j == k)
                        continue;

                    int x = points[k][0];
                    int y = points[k][1];

                    if (x1 <= x && x <= x2 && y <= y1 && y >= y2) {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    res++;
            }
        }
        return res;
    }
};