class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> x(32, 0), y = x;
        int i = 0;
        while (a > 0)
        {
            x[i] += a%2;
            a /= 2;
            i++;
        }
        i = 0;
        while (b > 0)
        {
            x[i] += b%2;
            b /= 2;
            i++;
        }
        i = 0;
        while (c > 0)
        {
            y[i] += c%2;
            c /= 2;
            i++;
        }
        int ans = 0;
        for (int i=0; i!=32; i++)
        {
            if (y[i] == 1 && x[i] == 0) ans++;
            else if (y[i] == 0) ans += x[i];
        }
        return ans;
    }
};