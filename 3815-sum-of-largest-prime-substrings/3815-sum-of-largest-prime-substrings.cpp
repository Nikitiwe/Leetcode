class Solution {
public:
    bool f(long long t)
    {
        if (t < 2) return 0;
        for (int i = 2; i <= sqrt(t); i++)
        {
            if (t % i == 0) return 0;
        }
        return 1;
    }

    long long sumOfLargestPrimes(string s) {
        long long a = -1, b = -1, c = -1;
        for (int i=0; i!=s.size(); i++)
        {
            long long t = 0;
            for (int j=i; j<s.size(); j++)
            {
                t *= 10;
                t += s[j] - '0';
                if (f(t) == 1)
                {
                    if (t > a)
                    {
                        c = b;
                        b = a;
                        a = t;
                    }
                    else if (t < a && t > b)
                    {
                        c = b;
                        b = t;
                    }
                    else if (t < b && t > c) c = t;
                }
            }
        }
        long long ans = 0;
        if (a != -1) ans += a;
        if (b != -1) ans += b;
        if (c != -1) ans += c;
        return ans;
    }
};