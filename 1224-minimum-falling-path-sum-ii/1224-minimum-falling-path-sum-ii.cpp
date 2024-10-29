class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        vector<vector<int>> ans(g.size(), vector<int> (g[0].size(), 10000000));
        for (int j=0; j!=g[0].size(); j++) ans[0][j]=g[0][j];
        for (int i=1; i<g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                int t=1000000;
                for (int k=0; k!=g[0].size(); k++) if (j!=k) t=min(t, ans[i-1][k]);
                ans[i][j]=t;
                ans[i][j]+=g[i][j];
            }
        }
        int t=1000000;
        for (int j=0; j!=g[0].size(); j++) t=min(t, ans[g.size()-1][j]);
        return t;
    }
};