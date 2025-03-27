class Solution {
public:
    int nthUglyNumber(int n, int aa, int bb, int cc) {
        long long ans = 2000000000, l = 1, r = 2000000000, m, a = aa, b = bb, c = cc;
        while (l <= r)
        {
            //m = l/2 + (r-l)/2;
            m = (l+r)/2;
            long long t = 0, del = c/gcd(c, b)*b;
            t = m/a + m/b + m/c - m/(a/gcd(a, b)*b) - m/(a/gcd(a, c)*c) - m/del + m/(a/gcd(a, del)*del);
            if (t >= n)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};