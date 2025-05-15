class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long ans = 0, mod = 1e9 + 7;
        int n = nums.size();
        vector<long> sum(n+1, 0);
        for (int i=0; i!=n; i++)
        {
            sum[i+1] = nums[i];
            sum[i+1] += sum[i];
        }
        long ls = 0;
        for (int i=0; i<n-2; i++)
        {
            ls += nums[i];
            if (ls * 3 > sum.back()) break;
            long l = i+1, r = n-1, m, res = n-1;
            while (l <= r)
            {
                m = (l+r)/2;
                long s = sum[m+1] - sum[i+1];
                if (s >= ls)
                {
                    res = min(res, m);
                    r = m-1;
                }
                else l = m+1;
            }
            //if (sum[res+1] - sum[i+1] > sum[n] - sum[res+1]) break;
            {
                l = res, r = n-2;
                long res2 = res - 1;
                while (l <= r)
                {
                    m = (l+r)/2;
                    long s = sum[m+1] - sum[i+1];
                    long ss = sum[n] - sum[m+1];
                    if (ss >= s)
                    {
                        res2 = max(res2, m);
                        l = m+1;
                    }
                    else r = m-1;
                }
                if (res2 >= res && res > i) ans += res2-res + 1;
            }
        }
        return ans % mod;
    }
};