class Solution {
public:
    int minimumSwap(string s, string w) {
        int a = 0, b = 0;
        if (s[0] > w[0]) a++;
        else if (s[0] < w[0]) b++;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i] > w[i]) a++;
            else if (s[i] < w[i]) b++;
        }
        if ((a+b)%2 == 1) return -1;
        int ans = a/2 + b/2;
        if (a%2 == 1) ans += 2;
        return ans;
    }
};