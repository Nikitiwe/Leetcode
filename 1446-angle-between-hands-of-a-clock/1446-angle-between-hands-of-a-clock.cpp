class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour=hour%12;
        double m=(double)minutes/60, h=(double)hour/12+m/12;
        if (abs(h-m)*360<=180) return abs(h-m)*360;
        else return 360-abs(h-m)*360;
    }
};