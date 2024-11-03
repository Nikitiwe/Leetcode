class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int ans=0;
        if (g[0][0]<=k) ans++;
        for (int j=1; j<g[0].size(); j++)
        {
            g[0][j]+=g[0][j-1];
            if (g[0][j]<=k) ans++;
            else break;
        }
        for (int i=1; i<g.size(); i++)
        {
            g[i][0]+=g[i-1][0];
            if (g[i][0]<=k) ans++;
            else break;
        }
        int l=g[0].size();
        for (int i=1; i<g.size(); i++)
        {
            for (int j=1; j<l; j++)
            {
                g[i][j]+=g[i][j-1]+g[i-1][j]-g[i-1][j-1];
                if (g[i][j]<=k) ans++;
                else
                {
                    l=j;
                    break;
                }
            }
        }
        return ans;
    }
};