class Solution {
public:
    double getMinDistSum(vector<vector<int>>& p) {
        int mix = p[0][0], mx = mix, miy = p[0][1], may = miy;
        for (int i=0; i!=p.size(); i++)
        {
            mix = min(mix, p[i][0]);
            mx = max(mx, p[i][0]);
            miy = min(miy, p[i][1]);
            may = max(may, p[i][1]);
        }
        double x = ((double)mix + mx)/2;
        double y = ((double)miy + may)/2;

        double ans = 0;
        for (int k = 0; k<p.size(); k++)
        {
            ans += sqrt((p[k][0] - x)*(p[k][0] - x) + (p[k][1] - y)*(p[k][1] - y));
        }

        int k = 10;
        double d = max(x, y);
        while (d > 0.00001)
        {
            double t = ans;
            while (1)
            {
                vector<double> delta{0, 0};
                {
                    for (double i=-d; i<d; i+=d/k)
                    {
                        for (double j=-d; j<d; j+=d/k)
                        {
                            double sum = 0;
                            for (int k = 0; k<p.size(); k++)
                            {
                                sum += sqrt(( x + i - p[k][0])*( x + i - p[k][0]) + ( y + j - p[k][1])*( y + j - p[k][1]));
                            }
                            if (sum < t)
                            {
                                t = sum;
                                delta = {i, j};
                            }
                        }
                    }
                }
                if (t < ans)
                {
                    x += delta[0];
                    y += delta[1];
                    ans = t;
                }
                else
                {
                    d *= 0.5;
                    break;
                }
            }
        }
        return ans;
    }
};