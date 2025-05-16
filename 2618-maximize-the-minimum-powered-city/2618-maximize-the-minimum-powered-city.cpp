class Solution {
public:
    long long maxPower(vector<int>& s, int rad, int k) {
        int n = s.size();
        vector<long long> arr(n + 1, 0);
        for (int i=0; i!=n; i++)
        {
            int a = max(0, i - rad);
            int b = min(n, i + rad + 1);
            arr[a] += s[i];
            arr[b] -= s[i];
        }
        long long ans = 0;
        long long l = 0, r = 1e12, m;
        while (l <= r)
        {
            m = (l+r)/2;
            vector<long long> t = arr;
            long long c = 0;
            for (int i=0; i!=n; i++)
            {
                if (t[i] < m)
                {
                    c += m - t[i];
                    int rr = min(n, i + 2*rad + 1);
                    t[rr] -= m - t[i];
                    t[i] = m;
                }
                t[i+1] += t[i];
            }
            if (c <= k)
            {
                ans = max(ans, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};