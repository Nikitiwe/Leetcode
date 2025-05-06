class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        //index++;
        maxSum -= n;
        long ans = 0, l = 0, r = 1e9, m;
        while (l <= r)
        {
            m = (l+r)/2;
            long sum = m;
            long rv = m - n + index + 1;
            long lv = m - index;
            if (index > 0)
            {
                if (lv > 0) sum += (lv + m - 1) * index / 2;
                else sum += (m - 1) * m / 2;
            }
            if (index < n-1)
            {
                if (rv > 0) sum += (rv + m - 1) * (n - index - 1) / 2;
                else sum += (m - 1) * m / 2;
            }
            if (sum <= maxSum)
            {
                ans = max(ans, m);
                l = m + 1;
            }
            else r = m - 1;
        }
        return ans + 1;
    }
};