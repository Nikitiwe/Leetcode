class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (abs(sx-fx)>t||abs(sy-fy)>t) return 0;
        if (sx==fx&&sy==fy&&t==1) return 0;
        return 1;
    }
};