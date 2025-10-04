class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = 0;
        while (i < j) {
            int width = min(height[i], height[j]);
            int length = j - i;
            res = max(res, width * length);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return res;
    }
};