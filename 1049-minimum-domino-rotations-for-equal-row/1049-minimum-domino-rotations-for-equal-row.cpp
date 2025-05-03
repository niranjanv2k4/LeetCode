class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = canConvert(tops, bottoms);
        if (result != -1)
            return result;
        result = canConvert(bottoms, tops);
        if (result != -1)
            return result;
        return -1;
    }
    
    int canConvert(vector<int>& top, vector<int>& bottom) {
        int t = 0, b = 0;
        int first = top[0], n = top.size();

        for (int i = 0; i < n; i++) {
            if (top[i] != first && bottom[i] != first) {
                return -1;
            } else if (top[i] != first)
                t++;
            else if (bottom[i] != first)
                b++;
        }

        return min(t, b);
    }
};