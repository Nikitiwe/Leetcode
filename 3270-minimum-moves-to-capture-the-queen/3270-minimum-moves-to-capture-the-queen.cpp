class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if ( a==e && (c!=a || (c==a && (d<min(b, f) || d>max(b, f) ) ) ) ) return 1;
        if ( b==f && (d!=b || (d==b && (c<min(a, e) || c>max(a, e) ) ) ) ) return 1;
        if (c+d==e+f && (a+b!=c+d || (a+b==c+d && (a<min(c, e) || a>max(c, e)) ) ) ) return 1;
        if (c-d==e-f && (a-b!=c-d || (a-b==c-d && (a<min(c, e) || a>max(c, e)) ) ) ) return 1;
        return 2;
    }
};