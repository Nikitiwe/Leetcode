class Solution {
public:
    string getHappyString(int n, int k) {
        string ans;
        int c = 3;
        for (int i=2; i<=n; i++) c *= 2;
        if (k > c) return "";
        {
            if (k <= c/3)
            {
                ans += 'a';
            }
            else if (k > c*2/3)
            {
                ans += 'c';
                k -= c/3;
                k -= c/3;
            }
            else
            {
                ans += 'b';
                k -= c/3;
            }
        }
        c /= 3;
        while (ans.size() < n)
        {
            if (k <= c/2)
            {
                if (ans.back() != 'a' ) ans += 'a';
                else ans += 'b';
            }
            else
            {
                if (ans.back() != 'c' ) ans += 'c';
                else ans += 'b';
                k -= c/2;
            }
            c /= 2;
        }
        return ans;
    }
};