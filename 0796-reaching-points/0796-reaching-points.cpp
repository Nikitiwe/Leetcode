class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        long lsx=sx, lsy=sy, ltx=tx, lty=ty;
        if (ltx==lsx&&lty==lsy) return 1;
        while (lsx<=ltx&&lsy<=lty)
        {
            if (10000*lty<ltx) {ltx=ltx-10000*lty; if (ltx==lsx&&lty==lsy) return 1;}
            if (lty>=10000*ltx) {lty=lty-10000*ltx; if (ltx==lsx&&lty==lsy) return 1;}
            if (lty<ltx) {ltx=ltx-lty; if (ltx==lsx&&lty==lsy) return 1;}
            else if (lty>=ltx) {lty=lty-ltx; if (ltx==lsx&&lty==lsy) return 1;}
        }
        return 0;
    }
}; // в предположении что координаты всегда неотрицательны