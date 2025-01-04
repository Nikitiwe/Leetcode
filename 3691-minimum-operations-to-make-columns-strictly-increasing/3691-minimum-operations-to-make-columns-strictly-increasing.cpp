class Solution {
public:
    int minimumOperations(vector<vector<int>>& g) {
        int ans=0;
        for (int j=0; j!=g[0].size(); j++)
        {
            int t=g[0][j];
            for (int i=1; i<g.size(); i++)
            {
                if (g[i][j]<=t) ans+=t-g[i][j]+1;
                t=max(t+1, g[i][j]);
            }
        }
        return ans;
    }
};