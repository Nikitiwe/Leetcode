class Solution {
public:
    double separateSquares(vector<vector<int>>& s) {
        double k = 0;
        for (int i=0; i!=s.size(); i++) k += (double)s[i][2]*s[i][2];
        k /=2;
        double l = 0, r = 2e9, m, ans = 0, eps = 0.000001;
        while (l <= r - eps)
        {
            m = (l+r)/2;
            double d = 0;
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i][1] + s[i][2] < m) d += (double)s[i][2]*s[i][2];
                else if (s[i][1] < m) d += (m - s[i][1]) * s[i][2];
            }
            if (d < k)
            {
                ans = max(ans, m);
                l = m;
            }
            else r = m;
        }
        return ans;
    }
};