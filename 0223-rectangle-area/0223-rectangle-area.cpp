class Solution {
public:
    int computeArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        if (x1>=x4||x3>=x2||y1>=y4||y3>=y2) return (x2-x1)*(y2-y1)+(x4-x3)*(y4-y3);
        return (x2-x1)*(y2-y1)+(x4-x3)*(y4-y3)-(min(x2, x4)-max(x1, x3))*(min(y2, y4)-max(y1, y3));
    }
};