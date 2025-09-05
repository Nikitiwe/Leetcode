int count_bits(long n)
{
    int c = 0;
    while (n > 0)
    {
        c += n%2;
        n /=2;
    }
    return c;
}

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long ans = 1e9, n = num1, m = num2;
        for (long k = 1; k <= 60; k++)
        {
            n -= m;
            if (n <= 0) break;
            if (n >= k && count_bits(n) <= k) ans = min(ans, k);
        }
        if (ans < 1e9) return ans;
        else return -1;
    }
};