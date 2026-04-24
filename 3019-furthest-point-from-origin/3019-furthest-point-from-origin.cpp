class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int res = 0, temp = 0;
        for (char ch : moves) {
            if (ch == 'R')
                res++;
            else if (ch == 'L')
                res--;
            else
                temp++;
        }
        return abs(res) + temp;
    }
};