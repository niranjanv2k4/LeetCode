class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = hour * 30 + (double)minutes / 2;
        double minute_angle = (double)minutes * 6;
        double gap = abs(hour_angle - minute_angle);

         return min(gap, 360 - gap);
    }
};