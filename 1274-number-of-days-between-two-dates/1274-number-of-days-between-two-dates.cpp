class Solution {
public:
    int daysBetweenDates(string s, string w) {
        vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int a = 0, b = 0, c = 0;
        a*=10; a += s[0] - '0';
        a*=10; a += s[1] - '0';
        a*=10; a += s[2] - '0';
        a*=10; a += s[3] - '0';
        b*=10; b += s[5] - '0';
        b*=10; b += s[6] - '0';
        c*=10; c += s[8] - '0';
        c*=10; c += s[9] - '0';
        int x = 0, y = 0, z = 0;
        x*=10; x += w[0] - '0';
        x*=10; x += w[1] - '0';
        x*=10; x += w[2] - '0';
        x*=10; x += w[3] - '0';
        y*=10; y += w[5] - '0';
        y*=10; y += w[6] - '0';
        z*=10; z += w[8] - '0';
        z*=10; z += w[9] - '0';
        int t = (a-1)*365;
        for (int i=1971; i<a; i++) if (i%4 == 0) t++;
        for (int i=0; i<b-1; i++) t += m[i];
        if (a != 2100 && a%4 == 0 && b > 2) t++;
        t += c;
        int d = (x-1)*365;
        for (int i=1971; i<x; i++) if (i%4 == 0) d++;
        for (int i=0; i<y-1; i++) d += m[i];
        if (x != 2100 && x%4 == 0 && y > 2) d++;
        d += z;
        return abs(d - t);
    }
};