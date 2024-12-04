class Solution {
public:
    string categorizeBox(int l, int w, int h, int m) {
        bool Bulky=0, Heavy=0;
        if (l>=10000||w>=10000||h>=10000) Bulky=1;
        else if ((long long)l*w*h>=1000000000) Bulky=1;
        if (m>=100) Heavy=1;
        if (Bulky&&Heavy) return "Both";
        if (Bulky&&~Heavy) return "Bulky";
        if (~Bulky&&Heavy) return "Heavy";
        return "Neither";
    }
};