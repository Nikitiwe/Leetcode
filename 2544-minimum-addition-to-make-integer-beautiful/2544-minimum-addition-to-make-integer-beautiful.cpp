class Solution {
public:
    long long makeIntegerBeautiful(long long n, int k) {
        long long ans = 0;
        int sum = 0;
        string s = to_string(n);
        for (int i=0; i!=s.size(); i++)
        {
            if (sum <= k)
            {
                ans *= 10;
                ans += s[i] - '0';
                sum += s[i] - '0';
                if (sum > k)
                {
                    while (sum > k)
                    {
                        long long t = ans;
                        t /= 10;
                        t++;
                        string ss = to_string(t);
                        int summ = 0;
                        for (int i=0; i!=ss.size(); i++) summ += ss[i] - '0';
                        ans = t;
                        sum = summ;
                    }
                    break;
                }
            }
        }
        while (ans < n) ans *= 10;
        return ans - n;
    }
};