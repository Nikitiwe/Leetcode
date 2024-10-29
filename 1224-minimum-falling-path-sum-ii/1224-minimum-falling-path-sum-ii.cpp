class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        vector<int> ans(g[0].size(), 10000000), prev=ans;
        for (int j=0; j!=g[0].size(); j++) prev[j]=g[0][j];
        for (int i=1; i<g.size(); i++)
        {
            int id=0;
            for (int j=0; j!=g[0].size(); j++)
            {
                if (prev[j]<prev[id]) id=j;
            }
            for (int j=0; j!=g[0].size(); j++)
            {
                if (j!=id)
                {
                    ans[j]=prev[id];
                }
                else
                {
                    int t=10000000;
                    for (int k=0; k!=g[0].size(); k++) if (j!=k) t=min(t, prev[k]);
                    ans[j]=t;
                }
                ans[j]+=g[i][j];
            }
            prev=ans;
        }
        int t=10000000;
        if (g.size()>1) for (int j=0; j!=g[0].size(); j++) t=min(t, ans[j]);
        else for (int j=0; j!=g[0].size(); j++) t=min(t, prev[j]);
        return t;
    }
};