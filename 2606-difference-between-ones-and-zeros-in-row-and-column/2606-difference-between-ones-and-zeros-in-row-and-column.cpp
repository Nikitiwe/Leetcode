class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        vector<int> r(g.size(), 0), c(g[0].size(), 0);
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]==1)
                {
                    r[i]+=2;
                    c[j]+=2;
                }
            }
        }
        int t=g[0].size()+g.size();
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                g[i][j]=r[i]+c[j]-t;
            }
        }
        return g;
    }
};