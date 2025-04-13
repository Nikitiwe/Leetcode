class Solution {
public:
    int minFlips(vector<vector<int>>& gg) {
        int ans = 10;
        int kk = 1;
        for (int i=0; i!=gg.size(); i++)
        {
            for (int j=0; j!=gg[i].size(); j++) kk <<= 1;
        }
        vector<vector<int>> zero(gg.size(), vector<int>(gg[0].size(), 0));
        for (int k=0; k!=kk; k++)
        {
            int t = k;
            int count = 0;
            vector<vector<int>> g = gg;
            for (int i=0; i!=g.size(); i++)
            {
                for (int j=0; j!=g[i].size(); j++)
                {
                    if (t%2 == 1)
                    {
                        count++;
                        g[i][j] = 1 - g[i][j];
                        if (i>0) g[i-1][j] = 1 - g[i-1][j];
                        if (j>0) g[i][j-1] = 1 - g[i][j-1];
                        if (i+1<g.size()) g[i+1][j] = 1 - g[i+1][j];
                        if (j+1<g[i].size()) g[i][j+1] = 1 - g[i][j+1];
                    }
                    t/=2;
                }
            }
            if (g == zero) ans = min(ans, count);
        }
        if (ans == 10) return -1;
        else return ans;
    }
};