class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int ans=0, ans2=0, i=1, j=2, red2=red, blue2=blue;
        while (1)
        {
            if (red-i>=0) {red=red-i; ans++; i=i+2;}
            else break;
            if (blue-j>=0) {blue=blue-j; ans++; j=j+2;}
            else break;
        }
        i=1; j=2;
        swap (red2, blue2);
        while (1)
        {
            if (red2-i>=0) {red2=red2-i; ans2++; i=i+2;}
            else break;
            if (blue2-j>=0) {blue2=blue2-j; ans2++; j=j+2;}
            else break;
        }
        return max(ans, ans2);
    }
};