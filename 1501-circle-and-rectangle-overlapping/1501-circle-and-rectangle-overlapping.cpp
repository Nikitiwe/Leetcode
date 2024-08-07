class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if ((xCenter+radius>=x1&&xCenter+radius<=x2)&&(yCenter>=y1&&yCenter<=y2)) return 1;
        if ((xCenter-radius>=x1&&xCenter-radius<=x2)&&(yCenter>=y1&&yCenter<=y2)) return 1;
        if ((xCenter>=x1&&xCenter<=x2)&&(yCenter+radius>=y1&&yCenter+radius<=y2)) return 1;
        if ((xCenter>=x1&&xCenter<=x2)&&(yCenter-radius>=y1&&yCenter-radius<=y2)) return 1;
        if ((xCenter>=x1&&xCenter<=x2)&&(yCenter>=y1&&yCenter<=y2)) return 1;
        radius*=radius;
        if ((xCenter-x1)*(xCenter-x1)+(yCenter-y1)*(yCenter-y1)<=radius) return 1;
        if ((xCenter-x2)*(xCenter-x2)+(yCenter-y1)*(yCenter-y1)<=radius) return 1;
        if ((xCenter-x1)*(xCenter-x1)+(yCenter-y2)*(yCenter-y2)<=radius) return 1;
        if ((xCenter-x2)*(xCenter-x2)+(yCenter-y2)*(yCenter-y2)<=radius) return 1;
        if ((xCenter-x2)*(xCenter-x2)<=radius&&(yCenter>=y1&&yCenter<=y2)) return 1;
        if ((yCenter-y1)*(yCenter-y1)<=radius&&(xCenter>=x1&&xCenter<=x2)) return 1;
        if ((xCenter-x1)*(xCenter-x1)<=radius&&(yCenter>=y1&&yCenter<=y2)) return 1;
        if ((yCenter-y2)*(yCenter-y2)<=radius&&(xCenter>=x1&&xCenter<=x2)) return 1;
        return 0;
    }
};