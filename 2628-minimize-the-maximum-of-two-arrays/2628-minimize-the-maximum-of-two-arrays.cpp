class Solution {
public:
    int minimizeSet(int d1, int d2, int c1, int c2) {
        long long ans = 2e9, l = 0, r = ans, m;
        while (l <= r)
        {
            m = (l+r)/2;
            int a = m/d1;
            int b = m/d2;
            int c = m*gcd(d1, d2)/d1/d2;
            if (m - c >= c1 + c2 && m - a >= c1 && m - b >= c2)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};