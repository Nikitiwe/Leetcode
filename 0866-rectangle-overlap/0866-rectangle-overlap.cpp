class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        int x=max(r1[0], r2[0]), y=max(r1[1], r2[1]), a=min(r1[2], r2[2]), b=min(r1[3], r2[3]);
        if (x<a&&y<b) return 1;
        else return 0;
    }
};