class Solution {
public:
    long long maxArea(vector<vector<int>>& c) {
        long long ans = -1;
        unordered_map<int, long long> mi, ma, xmi, xma;
        long long l = 1e7, r = -1, u = -1, d = 1e7;
        for (int i=0; i!=c.size(); i++)
        {
            l = min(l, (long long)c[i][0]);
            r = max(r, (long long)c[i][0]);
            d = min(d, (long long)c[i][1]);
            u = max(u, (long long)c[i][1]);

            if (mi.count(c[i][0]) != 0) mi[c[i][0]] = min(mi[c[i][0]], (long long)c[i][1]);
            else mi[c[i][0]] = (long long)c[i][1];
            if (ma.count(c[i][0]) != 0) ma[c[i][0]] = max(ma[c[i][0]], (long long)c[i][1]);
            else ma[c[i][0]] = (long long)c[i][1];

            if (xmi.count(c[i][1]) != 0) xmi[c[i][1]] = min(xmi[c[i][1]], (long long)c[i][0]);
            else xmi[c[i][1]] = (long long)c[i][0];
            if (xma.count(c[i][1]) != 0) xma[c[i][1]] = max(xma[c[i][1]], (long long)c[i][0]);
            else xma[c[i][1]] = (long long)c[i][0];
        }
        for (auto i = mi.begin(); i != mi.end(); i++)
        {
            long long x = i -> first;
            ans = max(ans, (x-l)*(ma[x] - mi[x]));
            ans = max(ans, (r-x)*(ma[x] - mi[x]));
        }
        for (auto i = xmi.begin(); i != xmi.end(); i++)
        {
            long long y = i -> first;
            ans = max(ans, (y-d)*(xma[y] - xmi[y]));
            ans = max(ans, (u-y)*(xma[y] - xmi[y]));
        }
        if (ans != 0) return ans;
        else return -1;
    }
};