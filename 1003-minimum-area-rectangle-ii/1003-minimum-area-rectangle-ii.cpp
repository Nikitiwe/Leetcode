class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& p) {
        double ans = 10000000000;
        double e = 0.000000001;
        for (int i=0; i!=p.size(); i++)
        {
            for (int j=0; j<p.size(); j++)
            {
                for (int a=0; a<p.size(); a++)
                {
                    for (int b=0; b<p.size(); b++)
                    {
                        if (a != b && a != i && a != j && b != i && b != j && i != j)
                        {
                            if ( abs(((double)p[i][0] - p[j][0])*((double)p[i][0] - p[j][0]) + ((double)p[i][1] - p[j][1])*((double)p[i][1] - p[j][1]) + 
                                  ((double)p[i][0] - p[a][0])*((double)p[i][0] - p[a][0]) + ((double)p[i][1] - p[a][1])*((double)p[i][1] - p[a][1])
                                - ((double)p[a][0] - p[j][0])*((double)p[a][0] - p[j][0]) - ((double)p[a][1] - p[j][1])*((double)p[a][1] - p[j][1])) < e &&
                                abs(((double)p[i][0] - p[j][0]) - ((double)p[a][0] - p[b][0])) < e && abs(((double)p[i][1] - p[j][1]) - ((double)p[a][1] - p[b][1])) < e
                                 ) ans = min(ans, sqrt(((double)p[i][0] - p[j][0])*((double)p[i][0] - p[j][0]) + ((double)p[i][1] - p[j][1])*((double)p[i][1] - p[j][1])) * 
                                                  sqrt(((double)p[i][0] - p[a][0])*((double)p[i][0] - p[a][0]) + ((double)p[i][1] - p[a][1])*((double)p[i][1] - p[a][1])) );
                        }
                    }
                }
            }
        }
        if (ans < 10000000000) return ans;
        else return 0;
    }
};